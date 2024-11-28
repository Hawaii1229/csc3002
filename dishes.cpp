dishes
void setupUi(QWidget *dishes)
{
    if (dishes->objectName().isEmpty())
        dishes->setObjectName(QString::fromUtf8("dishes"));
    dishes->resize(450, 200);

    // dishes' photos
    dishes_photo = new QGraphicsView(dishes);
    dishes_photo->setGeometry(QRect(20, 20, 140, 140));
    dishes_photo->setStyleSheet("QGraphicsView {"
                                 "  border: 2px solid #4caf50;"
                                 "  background-color: #f5f5f5;"
                                 "  border-radius: 10px; }");

    // name and price
    name = new QTextBrowser(dishes);
    name->setGeometry(QRect(180, 20, 240, 30));
    name->setFont(QFont("Microsoft YaHei", 14, QFont::Bold));

    price = new QTextBrowser(dishes);
    price->setGeometry(QRect(180, 60, 120, 30));
    price->setFont(QFont("Microsoft YaHei", 12, QFont::Italic));
    price->setStyleSheet("QTextBrowser { color: #ff5722; }");

    // introduction
    introduction = new QTextBrowser(dishes);
    introduction->setGeometry(QRect(180, 100, 240, 60));
    introduction->setFont(QFont("Microsoft YaHei", 10));
    introduction->setStyleSheet("QTextBrowser {"
                                 "  border: 1px solid #cfd8dc;"
                                 "  background-color: #ffffff; }");

    // number select frame
    quantity = new QSpinBox(dishes);
    quantity->setGeometry(QRect(320, 60, 100, 30));
    quantity->setStyleSheet("QSpinBox {"
                             "  border: 1px solid #cfd8dc;"
                             "  padding: 5px; }");

    retranslateUi(dishes);
}