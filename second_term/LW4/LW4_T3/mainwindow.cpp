#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString MainWindow::searchForVars(QString inputText) {
    std::string input = inputText.toStdString();
    std::regex pattern(R"((?!MainWindow)([A-Z][A-Za-z_]*?|int|float|char|bool|qint16|qint32|qint8|qfloat16|std::string|string|QString|QChar)(\*)?\s+(\*)?(?!main)(\w+)((\s*=)\s*(?!new)(?!malloc)([^\n;]+))?\s*;)");
    std::unordered_map<QString, int> type_counts;
    std::cmatch match;
    QString ans;
    while (std::regex_search(input.c_str(), match, pattern))
    {
        std::string type_name = match[1].str().c_str();
        std::string pointer = match[2].str().c_str();
        std::string pointer_ = " "; pointer_ += match[3].str().c_str();
        std::string variable_name = match[4].str().c_str();
        std::string default_value = match[7].str().c_str();
        type_counts[type_name.c_str()]++;
        ans += type_name.c_str();
        if(pointer.c_str() == "*")
        {
            ans+=pointer.c_str();
        }
        else if(pointer_.c_str() == " *")
        {
            ans+=pointer_.c_str();
        }
        else
        {
            ans += " ";
        }
        ans += variable_name.c_str();
        if (!default_value.empty())
        {
            ans+= " = ";
            ans+=default_value.c_str();
        }
        ans +="\n";
        input = match.suffix().first;
    }
    ans+="\n\n";

    for (const auto& i : type_counts)
    {
        ans += "Количество переменных: ";
        ans += i.first;
        ans+= ": ";
        ans+=QString::number(i.second);
        ans += "\n";
    }
    return ans;
}

QString MainWindow::varChangingPlace(QString inputText) {
    QStringList lineList = inputText.split("\n");
    QString ans;
    std::cmatch match;
    std::regex pattern(R"((\b\w+\b)((\[[^\]]*\])*)\s*=\s*(.*);)");
    for (int i = 0; i < lineList.size(); i++) {
        std::string line = lineList[i].toStdString();
        while (std::regex_search(line.c_str(), match, pattern)) {
            ans += "Строка " + QString::number(i + 1) + ": " + QString::fromStdString(match.str()) + "\n";
            line = match.suffix().first;
        }
    }
    return ans;
}


QString MainWindow::countClassesStructsArrays(QString inputText) {
    std::string input1 = inputText.toStdString();
    std::string input2 = input1;
    std::string input3 = input1;

    int classes = 0;
    int arrays = 0;
    int structs = 0;

    std::regex reg_array (R"(\w+\s+\w+\s*\[\s*\d+\s*\](;|(\s*=\s*\{)?))");
    std::regex reg_struct (R"((struct)\s+[a-zA-Z_][a-zA-Z0-9_]*\s*\{)");
    std::regex reg_classes (R"((class)\s+[a-zA-Z_][a-zA-Z0-9_]*\s*\{)");


    std::cmatch match;

    while (std::regex_search(input1.c_str(), match, reg_classes)) {
        classes++;
        input1 = match.suffix();
    }
    while (std::regex_search(input2.c_str(), match, reg_struct)) {
        structs++;
        input2 = match.suffix();
    }
    while (std::regex_search(input3.c_str(), match, reg_array)) {
        arrays++;
        input3 = match.suffix();
    }
    return QString("Всего классов: " + QString::number(classes) + "\nВсего структур: " + QString::number(structs) + "\nВсего массивов: " + QString::number(arrays));
}

QString MainWindow::prototypeList(QString inputText)
{
    QString ans;
    QStringList lineList = inputText.split("\n");
    std::regex pattern(R"((\w+\s*)(\*|\s)+\s*(\w+)\((.*?)\)\s*(\;|\{))");
    std::smatch match;
    int bracket = 0;
    for (int i = 0; i < lineList.size(); i++) {
        auto line = lineList[i].toStdString();
        for (size_t j = 0; j < line.size(); j++) {
            if (line[j] == '{')
                bracket++;
            if (line[j] == '}') {
                bracket--;
            }
        }

        while (!bracket && std::regex_search(line, match, pattern)) {
            std::string str = match[0].str();
            ans += QString::fromStdString(str) + '\n';
            line = match.suffix().str();
        }
    }
    return ans;
}


QString MainWindow::logicalMistakes(QString inputText) {
    std::string input =  inputText.toStdString();
    QString ans;
    std::regex pattern2("((const)\\s+(bool)\\s+([a-z]*)\\s*(=)\\s*(true|false)\\s*);");
    std::string buf;
    std::cmatch match2;
    while(std::regex_search(input.c_str(), match2, pattern2))
    {
        buf = "while(";
        buf += match2[4].str().c_str();
        buf.push_back(')');

        QStringList lineList = inputText.split('\n');
        for(int i=0;i<lineList.size(); ++i)
        {
            if(!strcmp(buf.c_str(),lineList[i].toStdString().c_str()))
            {
                ans+=match2[1].str().c_str();
                ans+='\n';
                ans+=lineList[i];
                ans+='\n';
            }
        }
        input = match2.suffix().first;
    }
    ans+='\n';
    std::regex pattern("(while\\s*\\(true\\)|while\\s*\\(false\\))");
    std::cmatch match;
    while(std::regex_search(input.c_str(),match,pattern))
    {
        ans+=match.str().c_str();
        ans+='\n';
        input = match.suffix().first;
    }
    return ans;
}

QString MainWindow::localVarsCount(QString line)
{
    QStringList lineList = line.split("\n");
    std::regex pattern(R"(\b(?!(struct|class|void|namespace|return)\s)(\w+)((\s+)|(\s*(\*)\s*))(\w+)\s*(=\s*(\S+))?\s*(,\s*\w+\s*(=\s*(\S+))?)*\;)");

    std::cmatch match;
    QString ans;
    int bracket = 0;

    for(int i = 0; i < lineList.size(); ++i) {
        std::string line = lineList[i].toStdString();
        for (size_t j = 0; j < line.size(); j++) {
            if (line[j] == '{')
                bracket++;
            if (line[j] == '}') {
                bracket--;
            }
        }
        while(bracket && std::regex_search(line.c_str(), match, pattern)) {
            ans += "Строка " + QString::number(i + 1) + ": " + QString::fromStdString(match[0].str()) + "\n";
            line = match.suffix().str();
        }
    }
    return ans;
}


QString MainWindow::overridedFuncsCount(QString inputText) {
        std::string input = inputText.toStdString();
        QString ans = "";
        std::cmatch match;
        std::regex pattern(R"(\b([a-zA-Z_][a-zA-Z0-9_]*)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*\(([^()]*)\)\s*\{)");
        std::map<std::string, std::vector<int>> f;
        int count_ = 0; 
        while (std::regex_search(input.c_str(), match, pattern)) {
            std::string f_name = match[2].str();
            std::string f_par = match[3].str();
            auto m_end = input.begin() + match.position() + match.length();
            f[f_name].push_back(count(input.begin(), m_end, '\n'));
            input = match.suffix().str();
        }
        for (const auto & it : f) {
            if (it.second.size() > 1) {
                ans += "Функции ";
                ans += QString::fromStdString(it.first);
                ans += " переопределены в строках: ";
                for (auto lin: it.second) {
                    ans += QString::number(lin) + " ";
                    count_++;
                }
                ans += '\n';
            }
        }
        ans += "\n\nКоличество: " + QString::number(count_);
        return ans;
}

QString MainWindow::branchDepth(QString inputText)
{
    QStringList lineList = inputText.split("\n");
    QString ans = "";
    std::regex pattern(R"(\b(if)\s*\(\S+.*\)\s*(\{?))");
    std::cmatch match;
    int bracket = 0;
    std::stack<int> s;

    for (int i = 0; i < lineList.size(); i++) {
        std::string line = lineList[i].toStdString();
        for (size_t j = 0; j < line.size(); j++) {
            if (line[j] == '{')
                bracket++;
            if (line[j] == '}') {
                if (!s.empty() && s.top() == bracket) {
                    s.pop();
                }
                bracket--;
            }
        }
        while(std::regex_search(line.c_str(), match, pattern)) {
            if (match[2].str() == "{") {
                s.push(bracket);
                ans += "Ветка на строке " + QString::number(i + 1) + " на глубине " + QString::number(s.size() + 1) + "\n";
            }
            else
                ans += "Ветка на строке " + QString::number(i + 1) + " на глубине " + QString::number(s.size() + 2) + "\n";
            line = match.suffix().str();
        }
    }
    return ans;
}


void MainWindow::on_pushButton_openFile_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Open File", "/Users/lllymuk/Desktop/OAiP/OAiP 2 sem/LW4_T3");
    if (path.isEmpty())
        return;
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QTextStream out(&file);

    QString PlaintText;
    while (!out.atEnd()) {
        QString tmp;
        out.readLineInto(&tmp);
        PlaintText.append(tmp + '\n');
    }
    ui->textBrowser->setText(PlaintText);
}


void MainWindow::on_pushButton_listOfPrototypes_clicked()
{
    QMessageBox::information(this, "", prototypeList(ui->textBrowser->toPlainText()));
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::information(this, "", countClassesStructsArrays(ui->textBrowser->toPlainText()));
}


void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::information(this, "", varChangingPlace(ui->textBrowser->toPlainText()));
}


void MainWindow::on_pushButton_2_clicked()
{
     QMessageBox::information(this, "", (ui->textBrowser->toPlainText()));
}


void MainWindow::on_pushButton_writeVars_clicked()
{
    QMessageBox::information(this, "", searchForVars(ui->textBrowser->toPlainText()));
}


void MainWindow::on_pushButton_7_clicked()
{
    QMessageBox::information(this, "", localVarsCount(ui->textBrowser->toPlainText()));
}


void MainWindow::on_pushButton_6_clicked()
{
    QMessageBox::information(this, "", overridedFuncsCount(ui->textBrowser->toPlainText()));
}


void MainWindow::on_pushButton_8_clicked()
{
    QMessageBox::information(this, "", branchDepth(ui->textBrowser->toPlainText()));
}


void MainWindow::on_pushButton_9_clicked()
{
    QMessageBox::information(this, "", logicalMistakes(ui->textBrowser->toPlainText()));
}

