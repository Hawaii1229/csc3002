order tob
void setupUi(QMainWindow *order_tob)
{
    if (order_tob->objectName().isEmpty())
        order_tob->setObjectName(QString::fromUtf8("order_tob"));
    order_tob->resize(520, 722);
    order_tob->setStyleSheet("background-color: #f8f9fa;");

    centralwidget = new QWidget(order_tob);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));

    // rolling area
    m_scrollArea = new QScrollArea(centralwidget);
    m_scrollArea->setObjectName(QString::fromUtf8("m_scrollArea"));
    m_scrollArea->setGeometry(QRect(10, 10, 500, 700));
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setStyleSheet(
        "QScrollArea { border: 2px solid #dcdcdc; border-radius: 8px; }"
        "QScrollBar:vertical { background: #f1f1f1; width: 12px; }"
        "QScrollBar::handle:vertical { background: #cccccc; border-radius: 6px; }"
        "QScrollBar::handle:vertical:hover { background: #aaaaaa; }");

    scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 498, 698));
    m_scrollArea->setWidget(scrollAreaWidgetContents);

    order_tob->setCentralWidget(centralwidget);

    // menu bar
    menubar = new QMenuBar(order_tob);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 520, 21));
    menubar->setStyleSheet("background-color: #ffffff; border-bottom: 1px solid #dcdcdc;");
    order_tob->setMenuBar(menubar);

    // status bar
    statusbar = new QStatusBar(order_tob);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    statusbar->setStyleSheet(
        "QStatusBar { background-color: #f1f1f1; border-top: 1px solid #dcdcdc; padding: 5px; }");
    order_tob->setStatusBar(statusbar);

    retranslateUi(order_tob);
    QMetaObject::connectSlotsByName(order_tob);
}

void retranslateUi(QMainWindow *order_tob)
{
    order_tob->setWindowTitle(QApplication::translate("order_tob", "Order Overview", nullptr));
}