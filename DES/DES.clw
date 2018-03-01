; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDESDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DES.h"

ClassCount=3
Class1=CDESApp
Class2=CDESDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DES_DIALOG

[CLS:CDESApp]
Type=0
HeaderFile=DES.h
ImplementationFile=DES.cpp
Filter=N

[CLS:CDESDlg]
Type=0
HeaderFile=DESDlg.h
ImplementationFile=DESDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CDESDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=DESDlg.h
ImplementationFile=DESDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DES_DIALOG]
Type=1
Class=CDESDlg
ControlCount=14
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350631492
Control6=IDC_EDIT2,edit,1350631552
Control7=IDC_EDIT3,edit,1350633540
Control8=IDC_EDIT4,edit,1350631492
Control9=IDC_ENCRYPT,button,1342242816
Control10=IDC_CLEAN,button,1342242816
Control11=IDC_DECRYPT,button,1342242816
Control12=IDC_STATIC,button,1342177287
Control13=IDC_RADIO1,button,1342177289
Control14=IDC_RADIO2,button,1342177289

