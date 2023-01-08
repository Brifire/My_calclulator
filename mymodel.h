#ifndef MYMODEL_H
#define MYMODEL_H
#include <QAbstractTableModel>


class MyModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit MyModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // MYMODEL_H
