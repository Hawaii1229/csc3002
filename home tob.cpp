home tob
void setupUi(QMainWindow *home_tob)
{
    if (home_tob->objectName().isEmpty())
        home_tob->setObjectName(QString::fromUtf8("home_tob"));
    home_tob->resize(450, 800);
    home_tob->setStyleSheet("background-color: #fcfcfc;");

    centralwidget = new QWidget(home_tob);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));

    QVBoxLayout *layout = new QVBoxLayout(centralwidget);

    // title
    QLabel *title = new QLabel("Home Page", centralwidget);
    QFont titleFont;
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("color: #333;");
    layout->addWidget(title);

    // botton1
    QPushButton *button1 = new QPushButton("Button 1", centralwidget);
    button1->setStyleSheet(
        "QPushButton { background-color: #0078d4; color: white; border-radius: 10px; padding: 10px; }"
        "QPushButton:hover { background-color: #005bb5; }");
    layout->addWidget(button1);

    // botton2
    QPushButton *button2 = new QPushButton("Button 2", centralwidget);
    button2->setStyleSheet(
        "QPushButton { background-color: #28a745; color: white; border-radius: 10px; padding: 10px; }"
        "QPushButton:hover { background-color: #218838; }");
    layout->addWidget(button2);

    home_tob->setCentralWidget(centralwidget);
}