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
  object LabeledEditFunc: TLabeledEdit
    Left = 8
    Top = 24
    Width = 592
    Height = 21
    EditLabel.Width = 62
    EditLabel.Height = 13
    EditLabel.Caption = 'Bool function'
    TabOrder = 0
    Text = '~A*~B*~C*D+~A*~B*C*D+~A*B*~C*D+~A*B*C*D+A*B*C*~D+A*B*C*D'
  end
  object ButtonCalc: TButton
    Left = 606
    Top = 22
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Let'#39's Go!'
    TabOrder = 1
    OnClick = ButtonCalcClick
  end
  object Memo1: TMemo
    Left = 256
    Top = 51
    Width = 425
    Height = 429
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 51
    Width = 242
    Height = 429
    ColCount = 2
    DefaultColWidth = 94
    DefaultRowHeight = 20
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 3
    RowHeights = (
      20)
  end
end
