#include "windowfunction.h"
#include "ui_windowfunction.h"

#include <QDebug>

WindowFunction::WindowFunction(WorkSpace *workspace_, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WindowFunction)
    , workspace(workspace_)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

    connect(ui->pushButtonExit,&QPushButton::clicked, this, &WindowFunction::closeWindow);
    connect(ui->pushButtonAdjVertex,&QPushButton::clicked, this, &WindowFunction::showMatrixAdjVertex);
    connect(ui->pushButtonAdjEdge,&QPushButton::clicked, this, &WindowFunction::showMatrixAdjEdge);
    connect(ui->pushButtonIncidence,&QPushButton::clicked, this, &WindowFunction::showMatrixIncidence);
    connect(ui->pushButtonSearchWidth,&QPushButton::clicked, this, &WindowFunction::searchWidth);
    connect(ui->pushButtonSearchDepth,&QPushButton::clicked, this, &WindowFunction::searchDepth);
    connect(ui->pushButtonPaint,&QPushButton::clicked, this, &WindowFunction::paintGraph);
    connect(ui->pushButtonDeikstra,&QPushButton::clicked, this, &WindowFunction::algDeikstra);
    connect(ui->pushButtonCodeP,&QPushButton::clicked, this, &WindowFunction::showCodeP);
    connect(ui->pushButtonFord,&QPushButton::clicked, this, &WindowFunction::algFord);
}

WindowFunction::~WindowFunction()
{
    delete ui;
}

void WindowFunction::closeWindow()
{
    this->close();
}

void WindowFunction::showMatrixAdjVertex()
{
    auto matrix = this->createMatrixAdjVertex();
    QStringList label;
    for (int i = 0; i < matrix.size(); ++i) {
        label << QString("Вершина %1").arg(i);
    }
    this->windowMatrix(label,label,matrix);
}

void WindowFunction::showMatrixAdjEdge()
{
    auto matrix = this->createMatrixAdjEdge();
    auto &edges = this->workspace->getAllEdge();
    QStringList label;
    for(const auto &edge : edges){
        label << QString("Ребро "+edge.get_vertex1()->getNum()+'-'+edge.get_vertex2()->getNum());
    }

    this->windowMatrix(label, label, matrix);
}

void WindowFunction::showMatrixIncidence()
{
    auto matrix = createMatrixAdjIncidence();
    auto edges = this->workspace->getAllEdge();
    auto vertexes = this->workspace->getAllVertex();
    QStringList label_h, label_v;
    for(const auto &edge : edges){
        label_h << QString("Ребро "+edge.get_vertex1()->getNum()+'-'+edge.get_vertex2()->getNum());
    }
    for(int i=0; i<vertexes.size(); i++){
        label_v << QString("Вершина %1").arg(i);
    }

    this->windowMatrix(label_h, label_v, matrix);
}

void WindowFunction::searchWidth()
{
    auto matrix = this->createMatrixAdjVertex();
    QVector<QVector<QString> > ans;
    QSet<QString> ind_check={"0"};
    QVector<QString> cur_vertex={"0"};
    QVector<QString> temp_vertex;

    for(int i=0; i<matrix.size(); ++i){
        ans.push_back(cur_vertex);
        temp_vertex.resize(0);
        for(auto &vertex : cur_vertex){
            for(int j=vertex.toInt()+1; j<matrix.size(); ++j){
                if((matrix[vertex.toInt()][j]!="0")&&(ind_check.find(QString::number(j))==ind_check.end())){
                    temp_vertex.push_back(QString::number(j));
                    ind_check.insert(QString::number(j));
                }
            }
        }
        if(temp_vertex.size()==0){
            break;
        }
        cur_vertex=temp_vertex;
    }

    QStringList label_h, label_v;
    for(int i=0; i<ans.size(); i++){
        label_v<<QString("Слой %1").arg(i);
    }

    int max_h=0;
    for(auto &item : ans){
        if(max_h<item.size()){
            max_h=item.size();
        }
    }

    label_h=QStringList(max_h,"-");

    QVector<QVector<QString> > result(ans.size(), QVector<QString>(max_h, "-"));
    for(int i=0; i<ans.size(); ++i){
        for(int j=0; j<ans[i].size(); ++j){
            result[i][j]=ans[i][j];
        }
    }

    this->windowMatrix(label_h, label_v, result);
}

void WindowFunction::searchDepth()
{
    auto matrix = this->createMatrixAdjVertex();
    QVector<int> ans;
    QVector<int> temp={0};

    auto dfs = [&matrix, &ans, &temp](auto&& self) -> void {
        if (temp.size() > ans.size()) {
            ans = temp;
        }

        int current = temp.back();

        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[current][i] != "0" && !temp.contains(i)) {
                temp.push_back(i);
                self(self);
                temp.pop_back();
            }
        }
    };
    dfs(dfs);

    QStringList label_h(1,"-"), label_v(1,"Цепочка");
    QVector<QVector<QString>> res={{QString::number(ans[0])}};

    for(int i=1; i<ans.size(); ++i){
        res[0][0]+="->"+QString::number(ans[i]);
    }

    this->windowMatrix(label_h, label_v, res);
}

void WindowFunction::paintGraph()
{
    auto matrix = this->createMatrixAdjVertex();
    QVector<QVector<int>> groups;
    QSet<int> check;

    int num_group=0;
    for(int i=0; i<matrix.size();++i){
        if(check.find(i)!=check.end()){
            continue;
        }
        check.insert(i);
        groups.push_back({});
        groups[num_group].push_back(i);
        for(int j=i+1; j<matrix[i].size(); ++j){
            if((check.find(j)!=check.end())||(matrix[i][j]!="0")||(std::any_of(
                    groups[num_group].begin(), groups[num_group].end(), [&](const int &a){
                    return matrix[a][j]!="0";
                }))){
                continue;
            }
            check.insert(j);
            groups[num_group].push_back(j);
        }
        ++num_group;
    }

    int max_h=0;
    for(auto &i : groups){
        if(i.size()>max_h){
            max_h=i.size();
        }
    }

    QStringList label_h(max_h, "-"), label_v;
    for(int i=0; i<groups.size(); ++i){
        label_v << QString("Группа %1").arg(i+1);
    }

    QVector<QVector<QString>> res(label_v.size(), QVector<QString>(label_h.size(),"-"));
    for(int i=0; i<groups.size(); ++i){
        for(int j=0; j<groups[i].size(); ++j){
            res[i][j]=QString::number(groups[i][j]);
        }
    }

    this->windowMatrix(label_h, label_v, res);
}

void WindowFunction::algDeikstra()
{
    auto matrix = this->createMatrixAdjVertex();
    QSet<int> check;
    QVector<int> ans(matrix.size(), -1);
    ans[0]=0;

    while(check.size()!=matrix.size()){
        int ind_min=-1;
        int min_len=100;
        for(int i=0; i<ans.size(); ++i){
            if((ans[i]>=0)&&(min_len>ans[i])&&(check.find(i)==check.end())){
                min_len=ans[i];
                ind_min=i;
            }
        }
        if(ind_min==-1){
            break;
        }
        check.insert(ind_min);
        for(int i=0; i<matrix[ind_min].size(); ++i){
            if((i!=ind_min)&&(check.find(i)==check.end())&&(matrix[ind_min][i]!="0")){
                if(ans[i]<=0){
                    ans[i]=min_len+matrix[ind_min][i].toInt();
                }
                else if(ans[i]>(min_len+matrix[ind_min][i].toInt())){
                    ans[i]=min_len+matrix[ind_min][i].toInt();
                }
            }
        }
    }

    QStringList label_h(1, "MinRoute"), label_v;
    for(int i=0; i<ans.size(); ++i){
        label_v << QString("До %1").arg(i);
    }

    QVector<QVector<QString>> res(1, QVector<QString>(ans.size(),"-"));
    for(int i=0; i<ans.size(); ++i){
        if(ans[i]!=-1){
            res[0][i]=QString::number(ans[i]);
        }
    }

    this->windowMatrix(label_h, label_v, res);
}

void WindowFunction::showCodeP()
{
    bool flag_not_tree=false;
    auto matrix = this->createMatrixAdjVertex();
    QSet<QString> ind_check={"0"};
    {
        QVector<QVector<QString> > ans;
        QVector<QString> cur_vertex={"0"};
        QVector<QString> temp_vertex;

        for(int i=0; i<matrix.size(); ++i){
            ans.push_back(cur_vertex);
            temp_vertex.resize(0);
            for(auto &vertex : cur_vertex){
                for(int j=vertex.toInt()+1; j<matrix.size(); ++j){
                    if((matrix[vertex.toInt()][j]!="0")&&(ind_check.find(QString::number(j))==ind_check.end())){
                        temp_vertex.push_back(QString::number(j));
                        ind_check.insert(QString::number(j));
                    }
                    else if((matrix[vertex.toInt()][j]!="0")&&(ind_check.find(QString::number(j))!=ind_check.end())){
                        flag_not_tree=true;
                    }
                }
            }
            if(temp_vertex.size()==0){
                break;
            }
            cur_vertex=temp_vertex;
        }
    }

    if(flag_not_tree){
        QMessageBox warningBox(this);
        warningBox.setIcon(QMessageBox::Warning);
        warningBox.setWindowTitle(tr("Warning"));
        warningBox.setText(tr("Это не дерево"));

        warningBox.setStyleSheet(
            "QMessageBox {"
            "   background-color: #f5f7fa;"
            "}"
            "QMessageBox QWidget {"
            "   background-color: #f5f7fa;"
            "   border: none;"
            "}"
            "QMessageBox QLabel {"
            "   color: #2c3e50;"
            "   min-width: 100px;"
            "}"
            "QMessageBox QPushButton {"
            "   background-color: #e74c3c;"
            "   color: white;"
            "   border-radius: 4px;"
            "   padding: 8px 16px;"
            "   font-weight: bold;"
            "   min-width: 40px;"
            "}"
            "QMessageBox QPushButton:hover {"
            "   background-color: #c0392b;"
            "}"
            "QMessageBox QPushButton:pressed {"
            "   background-color: #a5281b;"
            "}"
            );

        QPushButton *okButton = warningBox.addButton(QMessageBox::Ok);
        okButton->setText(tr("Понятно"));

        warningBox.exec();
    }
    else{
        QVector<QString> vertex_tree(ind_check.begin(), ind_check.end());
        std::sort(vertex_tree.begin(), vertex_tree.end(), [](const QString &a,const QString &b){
            return a[0] < b[0];
        });
        QVector<int> ans;
        while((ans.size()+2)<vertex_tree.size()){
            for(auto &vertex : vertex_tree){
                if(std::any_of(ans.begin(), ans.end(), [&](const auto &a){
                        return a==vertex.toInt();
                    })){
                    continue;
                }
                int num_neighbor=0;
                for(int i=0; i<matrix.size(); ++i){
                    if((i!=vertex.toInt())&&(matrix[i][vertex.toInt()]!="0")&&
                        (std::all_of(ans.begin(),ans.end(), [&](const auto &a){
                            return a!=i;
                        }))){
                        ++num_neighbor;
                    }
                }
                if(num_neighbor==1){
                    ans.push_back(vertex.toInt());
                    break;
                }
            }
        }

        QVector<QVector<QString>> res(1, QVector<QString>(ans.size()));
        for(int i=0; i<ans.size(); ++i){
            res[0][i]=QString::number(ans[i]);
        }
        QStringList label_h(ans.size(), "-"), label_v={"Код Прюфера:"};
        this->windowMatrix(label_h,label_v,res);
    }
}

void WindowFunction::algFord()
{
    auto matrix = this->createMatrixAdjVertex();
    for(int i=0; i<matrix.size(); ++i){
        for(int j=0; j<matrix[i].size(); ++j){
            if((matrix[i][j]=="0")&&(i!=j)){
                matrix[i][j]="9999";
            }
        }
    }

    for(int k=0; k<matrix.size(); ++k){
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix.size(); ++j){
                if((matrix[i][k].toInt()+matrix[k][j].toInt())<matrix[i][j].toInt()){
                    matrix[i][j]=QString::number(matrix[i][k].toInt()+matrix[k][j].toInt());
                }
            }
        }
    }

    for(int i=0; i<matrix.size(); ++i){
        for(int j=0; j<matrix[i].size(); ++j){
            if(matrix[i][j]=="9999"){
                matrix[i][j]="-";
            }
        }
    }
    QStringList label;
    for(int i=0; i<matrix.size(); ++i){
        label << QString("Вершина %1").arg(i);
    }
    this->windowMatrix(label,label,matrix);
}

QVector<QVector<QString>> WindowFunction::createMatrixAdjVertex()
{
    QVector<Edge> &edges = this->workspace->getAllEdge();
    QVector<Vertex> &vertexes = this->workspace->getAllVertex();
    QVector<QVector<QString>> matrix(vertexes.size(), QVector<QString>(vertexes.size(), "0"));

    for(const auto &edge : edges){
        matrix[edge.get_vertex1()->getNum().toInt()][edge.get_vertex2()->getNum().toInt()]=
            matrix[edge.get_vertex2()->getNum().toInt()][edge.get_vertex1()->getNum().toInt()]=
                edge.getWeight();
    }

    return matrix;
}

QVector<QVector<QString> > WindowFunction::createMatrixAdjEdge()
{
    QVector<Edge> &edges = this->workspace->getAllEdge();
    QVector<QVector<QString>> matrix(edges.size(), QVector<QString>(edges.size(), "0"));

    this->workspace->sortEdges();

    for(int i=0; i<edges.size(); ++i){
        for(int j=i+1; j<edges.size(); ++j){
            if((edges[i].get_vertex1()->getNum().toInt()==edges[j].get_vertex1()->getNum().toInt())||
                (edges[i].get_vertex1()->getNum().toInt()==edges[j].get_vertex2()->getNum().toInt())||
                (edges[i].get_vertex2()->getNum().toInt()==edges[j].get_vertex1()->getNum().toInt())||
                (edges[i].get_vertex2()->getNum().toInt()==edges[j].get_vertex2()->getNum().toInt())){
                matrix[i][j]=matrix[j][i]="1";
            }
        }
    }

    return matrix;
}

QVector<QVector<QString> > WindowFunction::createMatrixAdjIncidence()
{
    this->workspace->sortEdges();

    QVector<Edge> &edges = this->workspace->getAllEdge();
    QVector<Vertex> &vertexes = this->workspace->getAllVertex();
    QVector<QVector<QString>> matrix(vertexes.size(), QVector<QString>(edges.size(), "0"));

    for(int i=0; i<edges.size(); i++){
        matrix[edges[i].get_vertex1()->getNum().toInt()][i]=
            matrix[edges[i].get_vertex2()->getNum().toInt()][i]="1";
    }

    return matrix;
}

void WindowFunction::windowMatrix(QStringList label_h, QStringList label_v, QVector<QVector<QString> > matrix) const
{
    QDialog *matrixDialog = new QDialog();
    matrixDialog->setModal(false);
    matrixDialog->setWindowTitle(tr("Матрица"));
    matrixDialog->resize(600, 400);
    matrixDialog->setStyleSheet("QWidget {background: rgba(200, 200, 200, 0.95); border: none;}");

    QTableWidget *table = new QTableWidget(matrixDialog);
    table->setStyleSheet(
        "QTableWidget {"
        "   gridline-color: #cccccc;"
        "}"
        "QTableWidget::item {"
        "   color: #000000;"
        "   border: 1px solid #dddddd;"
        "   font-weight: 500;"
        "}"
        );

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::NoSelection);
    table->setFocusPolicy(Qt::NoFocus);

    table->setRowCount(label_v.size());
    table->setColumnCount(label_h.size());

    table->setHorizontalHeaderLabels(label_h);
    table->setVerticalHeaderLabels(label_v);


    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            QTableWidgetItem *item = new QTableWidgetItem(matrix[i][j]);
            item->setTextAlignment(Qt::AlignCenter);
            table->setItem(i, j, item);
        }
    }

    QPushButton *buttonOk = new QPushButton(tr("Назад"), matrixDialog);
    buttonOk->setFixedWidth(160);
    buttonOk->setStyleSheet("QPushButton {"
                            "background-color: #ff5555;"
                            "color: #000000;"
                            "border: 2px solid #cc0000;"
                            "border-radius: 6px;"
                            "padding: 8px 16px;"
                            "font: bold 14px 'Arial';"
                            "min-width: 100px;"
                            "outline: none;"
                            "}"
                            "QPushButton:hover {"
                            "background-color: #ff7777;"
                            "border-color: #dd2222;"
                            "}"
                            "QPushButton:pressed {"
                            "background-color: #dd2222;"
                            "border-color: #bb1111;"
                            "color: #111111;"
                            "}"
                            "QPushButton:disabled {"
                            "background-color: #aa9999;"
                            "color: #555555;"
                            "border-color: #998888;"
                            "}");

    QVBoxLayout *mainLayout = new QVBoxLayout(matrixDialog);
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    mainLayout->addWidget(table);
    buttonLayout->addWidget(buttonOk);
    mainLayout->addLayout(buttonLayout);

    connect(buttonOk, &QPushButton::clicked, matrixDialog, &QDialog::accept);

    matrixDialog->show();

    matrixDialog->setAttribute(Qt::WA_DeleteOnClose);
}
