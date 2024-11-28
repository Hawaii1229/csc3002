mainwindow toc
void setupUi(QMainWindow *MainWindow_toc)
{
    if (MainWindow_toc->objectName().isEmpty())
        MainWindow_toc->setObjectName(QString::fromUtf8("MainWindow_toc"));
    MainWindow_toc->resize(450, 800);
    MainWindow_toc->setMinimumSize(QSize(450, 800));
    MainWindow_toc->setMaximumSize(QSize(450, 843));

    // beauty window's background color
    MainWindow_toc->setStyleSheet("background-color: #f7f7f7;");

    action = new QAction(MainWindow_toc);
    action->setObjectName(QString::fromUtf8("action"));

    centralwidget = new QWidget(MainWindow_toc);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));

    QVBoxLayout *mainLayout = new QVBoxLayout(centralwidget);

    // set title sample
    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    QFont titleFont;
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    label->setFont(titleFont);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("color: #333333;");
    mainLayout->addWidget(label);

    // beauty rolling area
    m_scrollArea = new QScrollArea(centralwidget);
    m_scrollArea->setObjectName(QString::fromUtf8("m_scrollArea"));
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setStyleSheet(
        "QScrollArea { border: 1px solid #dddddd; border-radius: 5px; }"
        "QScrollBar:vertical { background: #e1e1e1; width: 10px; }"
        "QScrollBar::handle:vertical { background: #a3a3a3; border-radius: 5px; }");
    mainLayout->addWidget(m_scrollArea);

    scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
    m_scrollArea->setWidget(scrollAreaWidgetContents);

    MainWindow_toc->setCentralWidget(centralwidget);

    statusbar = new QStatusBar(MainWindow_toc);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow_toc->setStatusBar(statusbar);

    menubar = new QMenuBar(MainWindow_toc);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setStyleSheet("QMenuBar { background-color: #f1f1f1; border: 1px solid #dddddd; }");
    menu = new QMenu(menubar);
    menu->setObjectName(QString::fromUtf8("menu"));
    menubar->addAction(menu->menuAction());
    menu->addAction(action);
    MainWindow_toc->setMenuBar(menubar);

    retranslateUi(MainWindow_toc);

    QObject::connect(action, SIGNAL(triggered()), MainWindow_toc, SLOT(close()));
    QMetaObject::connectSlotsByName(MainWindow_toc);
}