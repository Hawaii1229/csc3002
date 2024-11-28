income tob
void setupUi(QMainWindow *income_tob)
{
    if (income_tob->objectName().isEmpty())
        income_tob->setObjectName(QString::fromUtf8("income_tob"));
    income_tob->resize(450, 800);
    income_tob->setStyleSheet("background-color: #fcfcfc;");

    centralwidget = new QWidget(income_tob);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));

    QVBoxLayout *layout = new QVBoxLayout(centralwidget);

    // title
    QLabel *title = new QLabel("Income Overview", centralwidget);
    QFont titleFont;
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("color: #222222;");
    layout->addWidget(title);

    // all income display
    QLabel *incomeLabel = new QLabel("Total Income:", centralwidget);
    incomeLabel->setStyleSheet("font-size: 16px; color: #555555;");
    layout->addWidget(incomeLabel);

    QLCDNumber *incomeDisplay = new QLCDNumber(centralwidget);
    incomeDisplay->setStyleSheet(
        "QLCDNumber { border: 2px solid #aaaaaa; border-radius: 5px; background: #ffffff; }");
    layout->addWidget(incomeDisplay);

    // botton
    QPushButton *confirmButton = new QPushButton("Confirm", centralwidget);
    confirmButton->setStyleSheet(
        "QPushButton { background-color: #4caf50; color: white; font-size: 16px; border-radius: 5px; }"
        "QPushButton:hover { background-color: #45a049; }");
    layout->addWidget(confirmButton);

    income_tob->setCentralWidget(centralwidget);
}