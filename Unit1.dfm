object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 
    #1041#1091#1083#1077#1074#1099#1077' '#1092#1091#1085#1082#1094#1080#1080' - '#1058#1072#1073#1083#1080#1094#1072' '#1080#1089#1090#1080#1085#1085#1086#1089#1090#1080' | '#1052#1080#1085#1080#1084#1080#1079#1072#1094#1080#1103' '#1084#1077#1090#1086#1076#1086#1084' '#1050#1074#1072#1081#1085 +
    #1072' - '#1052#1072#1082'-'#1050#1083#1072#1089#1082#1080' '
  ClientHeight = 486
  ClientWidth = 719
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    719
    486)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 522
    Top = 351
    Width = 157
    Height = 19
    Caption = #1052#1080#1085#1080#1084#1072#1083#1100#1085#1072#1103' '#1044#1053#1060
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label2: TLabel
    Left = 8
    Top = 0
    Width = 136
    Height = 21
    Caption = #1041#1091#1083#1077#1074#1072#1103' '#1092#1091#1085#1082#1094#1080#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 144
    Top = 73
    Width = 200
    Height = 25
    Caption = #1058#1072#1073#1083#1080#1094#1072' '#1080#1089#1090#1080#1085#1085#1086#1089#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label4: TLabel
    Left = 522
    Top = 82
    Width = 159
    Height = 16
    Caption = #1054#1087#1077#1088#1072#1094#1080#1080' '#1087#1088#1077#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object ButtonCalc: TButton
    Left = 634
    Top = 26
    Width = 81
    Height = 21
    Anchors = [akTop, akRight]
    Caption = #1055#1086#1076#1089#1095#1080#1090#1072#1090#1100
    TabOrder = 0
    OnClick = ButtonCalcClick
    ExplicitLeft = 606
  end
  object Memo1: TMemo
    Left = 479
    Top = 104
    Width = 233
    Height = 241
    ScrollBars = ssVertical
    TabOrder = 1
    Visible = False
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 104
    Width = 465
    Height = 376
    ColCount = 2
    DefaultColWidth = 80
    DefaultRowHeight = 20
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 2
    Visible = False
    RowHeights = (
      20)
  end
  object Memo2: TMemo
    Left = 479
    Top = 376
    Width = 233
    Height = 104
    ScrollBars = ssVertical
    TabOrder = 3
    Visible = False
  end
  object Edit1: TEdit
    Left = 8
    Top = 26
    Width = 621
    Height = 21
    TabOrder = 4
    Text = '~A*~B*~C*D+~A*~B*C*D+~A*B*~C*D+~A*B*C*D+A*B*C*~D+A*B*C*D'
    OnKeyPress = Edit1KeyPress
  end
  object CheckBox1: TCheckBox
    Left = 8
    Top = 49
    Width = 209
    Height = 17
    Caption = #1042#1099#1074#1086#1076#1080#1090#1100' '#1087#1088#1086#1084#1077#1078#1091#1090#1086#1095#1085#1099#1077' '#1086#1087#1077#1088#1072#1094#1080#1080
    Checked = True
    State = cbChecked
    TabOrder = 5
  end
end
