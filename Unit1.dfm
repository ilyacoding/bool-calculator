object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1050#1072#1083#1100#1082#1091#1083#1103#1090#1086#1088' '#1073#1091#1083#1077#1074#1099#1093' '#1092#1091#1085#1082#1094#1080#1081
  ClientHeight = 488
  ClientWidth = 689
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    689
    488)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 448
    Top = 367
    Width = 30
    Height = 13
    Caption = 'Result'
  end
  object Label2: TLabel
    Left = 8
    Top = 7
    Width = 62
    Height = 13
    Caption = 'Bool function'
  end
  object ButtonCalc: TButton
    Left = 606
    Top = 22
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Let'#39's Go!'
    TabOrder = 0
    OnClick = ButtonCalcClick
  end
  object Memo1: TMemo
    Left = 256
    Top = 53
    Width = 425
    Height = 308
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 53
    Width = 242
    Height = 427
    ColCount = 2
    DefaultColWidth = 94
    DefaultRowHeight = 20
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 2
    ColWidths = (
      94
      94)
    RowHeights = (
      20)
  end
  object Memo2: TMemo
    Left = 256
    Top = 386
    Width = 425
    Height = 94
    ScrollBars = ssVertical
    TabOrder = 3
  end
  object Edit1: TEdit
    Left = 8
    Top = 26
    Width = 592
    Height = 21
    TabOrder = 4
    Text = '~A*~B*~C*D+~A*~B*C*D+~A*B*~C*D+~A*B*C*D+A*B*C*~D+A*B*C*D'
    OnKeyPress = Edit1KeyPress
  end
end
