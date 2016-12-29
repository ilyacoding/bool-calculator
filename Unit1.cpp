//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "iostream"
//#include "fstream"
#include "string"
#include "vector"
#include <algorithm>
#include <functional>
#include <sstream>
#include <cctype>
#include <locale>
#include <iostream>
#include <iomanip>
#include "boost/algorithm/string.hpp"
#include "boost/lexical_cast.hpp"

using namespace std;

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


string UnicodeToString(UnicodeString us) {
	string result = AnsiString(us.t_str()).c_str();
	return result;
}

template <typename T>
string ToStr(T Data)
{
	 ostringstream ss;
	 ss << Data;
	 return ss.str();
}

enum Lexem {
	ID, PLUS, MUL, INVERSE
};

class Token {
public:
	Token(string ss, Lexem lx) : str(ss), lex(lx) {inv = false;}
	Token(Lexem lx) : lex(lx) {str = ""; inv = false;}
	string str;
	Lexem lex;
	bool inv;
};

class IDD {
public:
	IDD(string s, int in, bool v) : id(s), inv(in), value(v) {}
	string id;
	int value;
	bool inv;
};

class Menterm {
public:
	vector<int> v;
	Menterm(int x, int n)
	{
		while(x) {
			if (x&1)
				v.push_back(1);
			else
				v.push_back(0);
			x >>= 1;
		}
		while (v.size() < n) v.push_back(0);
		reverse(v.begin(),v.end());
	}
	Menterm(vector<int> vv)
	{
		v = vv;
    }
	int size();
	string str();
	string Fstr(vector<IDD> vars);
	int count();
};

string Menterm::str()
{
	string s = "";
	for (int i = 0; i < v.size(); i++)
		if (v[i] > -1)
			s += boost::lexical_cast<string>(v[i]);
		else
			s += "-";
	return s;
}

int Menterm::count()
{
	int x = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 1)
			x++;
	}
	return x;
}

string Menterm::Fstr(vector<IDD> vars)
{
	string s = "";
	for (int i = 0; i < v.size(); i++)
		if (v[i] == 1)
			s += vars[i].id;
		else if (v[i] == 0)
			s += "~" + vars[i].id;
		else
			s += "-";
	return s;
}

int Menterm::size()
{
	return v.size();
}

vector<vector<Token> > func;
vector<Token> tokens;
vector<int> table;
int table_amount;

vector<Menterm> SDNF;
vector<vector<Menterm> > Group;

vector<string> GetStrLexems(string str)
{
	string buf = "";
	boost::algorithm::trim(str);
	vector<string> lexems;
	int j = 0;
	boost::algorithm::trim(str);
	while (j < str.length())
	{
		if (isalpha(str[j]) || isdigit(str[j]))
		{
			while ((isalpha(str[j]) || isdigit(str[j])) && (j < str.length())) buf += str[j++];
			if (buf.length() > 0) {
				boost::algorithm::trim(buf);
				lexems.push_back(buf);
				buf = "";
			}
		} else {
			lexems.push_back(string(1, str[j]));
			j++;
		}
	}
	return lexems;
}

string TokenToStr(Lexem lex)
{
	switch (lex)
	{
	case ID:
		return "ID";
		break;
	case PLUS:
		return "PLUS";
		break;
	case MUL:
		return "MUL";
		break;
	case INVERSE:
		return "INVERSE";
		break;
	default:
		return "";
		break;
	}
}

vector<int> convert(int x, int n) {
	vector<int> ret;
	while(x) {
		if (x&1)
			ret.push_back(1);
		else
			ret.push_back(0);
		x >>= 1;
	}
	while (ret.size() < n) ret.push_back(0);
	reverse(ret.begin(),ret.end());
	return ret;
}

bool isValidVar(string str)
{
	if (!isalpha(str[0]) && (str[0] != '_')) return false;
	for (int i = 0; i < str.length(); i++)
	{
		if (!isalnum(str[i]) && (str[0] != '_')) return false;
	}
	return true;
}

bool ParseTokens(vector<string> lex)
{
	tokens.clear();
	for (int i = 0; i < lex.size(); i++)
	{
		if (lex[i] == "+")
			tokens.push_back(Token(lex[i], PLUS));
		else if (lex[i] == "*")
			tokens.push_back(Token(lex[i], MUL));
		else if (lex[i] == "~")
			tokens.push_back(Token(lex[i], INVERSE));
		else if (isValidVar(lex[i]))
			tokens.push_back(Token(lex[i], ID));
		else {
			return false;
		}
	}

	for (int i = 0; i < tokens.size(); i++)
	{
		if (tokens[i].lex == INVERSE)
		{
			if (i + 1 < tokens.size())
			{
				if (tokens[i + 1].lex == ID)
				{
					tokens[i + 1].inv = true;
					tokens.erase(tokens.begin() + i);
				} else {
					return false;
                }
			} else {
				return false;
            }
        }
    }

	return true;
}

void ParseFunc() {
	func.clear();
	vector<Token> el;
	for (int i = 0; i < tokens.size(); i++)
	{
		while (tokens[i].lex != PLUS && i < tokens.size())
		if (tokens[i].lex != MUL)
			el.push_back(tokens[i++]);
		else
			i++;
		func.push_back(el);
		el.clear();
	}
}

vector<IDD> GetIDD(vector<vector<Token> > func)
{
	vector<IDD> v;
	for (int i = 0; i < func.size(); i++)
	{
		for (int j = 0; j < func[i].size(); j++)
		{
			bool added = false;
			for (int k = 0; k < v.size(); k++)
				if (v[k].id == func[i][j].str)
					added = true;
			if (!added)
			{
				v.push_back(IDD(func[i][j].str, func[i][j].inv, false));
			}
		}
	}
	return v;
}

int GetValue(vector<vector<Token> > func, vector<IDD> val)
{
	for (int i = 0; i < func.size(); i++)
	{
		for (int j = 0; j < func[i].size(); j++)
		{
			int value;
			for (int k = 0; k < val.size(); k++)
				if (func[i][j].str == val[k].id)
				{
					if (func[i][j].inv)
						value = 1 - val[k].value;
					else
						value = val[k].value;
					func[i][j].inv = false;
				}
			if (value)
				func[i][j].str = "1";
			else
				func[i][j].str = "0";
		}
	}
	for (int i = 0; i < func.size(); i++)
	{
		bool isOne = true;
		for (int j = 0; j < func[i].size(); j++)
		{
			if (func[i][j].str == "0") {
				isOne = false;
			}
		}
		if (isOne)
			return 1;
	}
	return 0;
}

void SetValues(vector<IDD> & value, vector<int> val)
{
	for (int i = 0; i < val.size(); i++)
	{
		value[i].value = val[i];
    }
}

string GetVars(vector<IDD> var)
{
	string s = "";
	for (int i = 0; i < var.size(); i++)
		s += var[i].id;
	return s;
}

string GetValues(vector<int> var)
{
	string s = "";
	for (int i = 0; i < var.size(); i++)
		s += boost::lexical_cast<string>(var[i]);
	return s;
}

// Glue
bool CanGlue(Menterm x, Menterm y)
{

}

Menterm Glue(Menterm x, Menterm y)
{

}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonCalcClick(TObject *Sender)
{
	Memo1->Clear();
	SDNF.clear();
	func.clear();
	tokens.clear();
	table.clear();
	if (!ParseTokens(GetStrLexems(UnicodeToString(LabeledEditFunc->Text))))
	{
		Memo1->Lines->Add("Parse error.");
	}
	ParseFunc();
	/*for (int i = 0; i < tokens.size(); i++)
	{
		Memo1->Lines->Add("-> Token: ");
		Memo1->Lines->Add((TokenToStr(tokens[i].lex)).c_str());
		Memo1->Lines->Add((tokens[i].str).c_str());
		if (tokens[i].inv)
			Memo1->Lines->Add("-> ID inversed");
		Memo1->Lines->Add("");
	}
	Memo1->Lines->Add(">>>>>");
	Memo1->Lines->Add("");


	for (int i = 0; i < func.size(); i++)
	{
		for (int j = 0; j < func[i].size(); j++)
		{
			Memo1->Lines->Add(func[i][j].str.c_str());
		}
	}
    	for (int i = 0; i < val.size(); i++)
	{
		Memo1->Lines->Add(val[i].id.c_str());
		if (val[i].inv)
			Memo1->Lines->Add("INV");
	}
	*/


	vector<int> vs;
	vector<IDD> val = GetIDD(func);

	table_amount = val.size();
	for (int i = 0; i < pow(2.0, table_amount); i++) {
		val = GetIDD(func);
		vs = convert(i, table_amount);
		SetValues(val, vs);
		table.push_back(GetValue(func, val));
    }


	StringGrid1->RowCount = pow(2.0, table_amount) + 1;
	StringGrid1->Cells[0][0] = (GetVars(val).c_str());
	StringGrid1->Cells[1][0] = ("Value");
	for (int i = 0; i < table.size(); i++) {
		StringGrid1->Cells[0][i + 1] = ((Menterm(i, table_amount).str().c_str()));
		if (table[i]) {
			StringGrid1->Cells[1][i + 1] = ("1");
		} else {
			StringGrid1->Cells[1][i + 1] = ("0");
		}

	}
	// ENDED TABLE

	// Get SDNF
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i])
			SDNF.push_back(Menterm(i, table_amount));
	}


	for (int i = 0; i < SDNF.size(); i++)
	{
		Memo1->Lines->Add((SDNF[i].Fstr(GetIDD(func)) + " | " + boost::lexical_cast<string>(SDNF[i].count())).c_str());
		if (i < SDNF.size() - 1) Memo1->Lines->Add("+");
	}
	Memo1->Lines->Add(">>>");

	vector<Menterm> tmp_group;
	for (int i = 0; i < table_amount + 1; i++)
		Group.push_back(tmp_group);

	for (int i = 0; i < Group.size(); i++)
	{
		for (int j = 0; j < SDNF.size(); j++)
		{
			if (i == SDNF[j].count())
			{
				Group[i].push_back(SDNF[j]);
			}
		}
	}

	for (int i = 0; i < Group.size(); i++)
	{
		Memo1->Lines->Add((boost::lexical_cast<string>(i)).c_str());
		for (int j = 0; j < Group[i].size(); j++)
		{
		   Memo1->Lines->Add(Group[i][j].str().c_str());

        }
    }
}
//---------------------------------------------------------------------------

