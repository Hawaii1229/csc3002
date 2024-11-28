menu tob
void setupUi(QMainWindow *Menu)
{
    if (Menu->objectName().isEmpty())
        Menu->setObjectName(QString::fromUtf8("Menu"));
    Menu->resize(900, 700);
    centralwidget = new QWidget(Menu);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));

    // TableView beautify
    tableView = new QTableView(centralwidget);
    tableView->setObjectName(QString::fromUtf8("tableView"));
    tableView->setGeometry(QRect(60, 30, 780, 400));
    tableView->setStyleSheet("QTableView {"
                             "  background-color: #f7f7f7;"
                             "  alternate-background-color: #e8f5e9;"
                             "  gridline-color: #bdbdbd;"
                             "  border: 1px solid #cfd8dc; }"
                             "QTableView::item:hover {"
                             "  background: #c8e6c9; }");

    // botton style unified
    pushButton = new QPushButton(centralwidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(250, 450, 100, 40));
    pushButton->setStyleSheet("QPushButton {"
                              "  background-color: #4caf50;"
                              "  color: white;"
                              "  border-radius: 5px;"
                              "  font-weight: bold; }"
                              "QPushButton:hover {"
                              "  background-color: #66bb6a; }");

    pushButton_2 = new QPushButton(centralwidget);
    pushButton_2->setGeometry(QRect(370, 450, 100, 40));
    pushButton_2->setStyleSheet(pushButton->styleSheet());

    pushButton_3 = new QPushButton(centralwidget);
    pushButton_3->setGeometry(QRect(490, 450, 100, 40));
    pushButton_3->setStyleSheet(pushButton->styleSheet());

    pushButton_4 = new QPushButton(centralwidget);
    pushButton_4->setGeometry(QRect(610, 450, 100, 40));
    pushButton_4->setStyleSheet(pushButton->styleSheet());

    // input area grouped
    QGroupBox *inputGroup = new QGroupBox(centralwidget);
    inputGroup->setGeometry(QRect(60, 510, 780, 150));
    inputGroup->setTitle("Input Section");
    inputGroup->setStyleSheet("QGroupBox {"
                              "  border: 1px solid #cfd8dc;"
                              "  margin-top: 10px;"
                              "  font-weight: bold; }");

    name = new QLineEdit(inputGroup);
    name->setGeometry(QRect(100, 30, 200, 30));
    price = new QSpinBox(inputGroup);
    price->setGeometry(QRect(340, 30, 100, 30));

    introduction = new QTextEdit(inputGroup);
    introduction->setGeometry(QRect(100, 80, 600, 50));
    introduction->setStyleSheet("QTextEdit {"
                                 "  border: 1px solid #cfd8dc;"
                                 "  background-color: #ffffff; }");

    Menu->setCentralWidget(centralwidget);
    menubar = new QMenuBar(Menu);
    Menu->setMenuBar(menubar);
    statusbar = new QStatusBar(Menu);
    Menu->setStatusBar(statusbar);

    retranslateUi(Menu);
}