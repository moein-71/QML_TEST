#include "TaskModel.h"

TaskModel::TaskModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_tasks << "work 1" << "work 2" << "work 3";
}

int TaskModel::rowCount(const QModelIndex &) const {
    return m_tasks.count();
}

QVariant TaskModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= m_tasks.size())
        return QVariant();

    if (role == NameRole)
        return m_tasks.at(index.row());

    return QVariant();
}

QHash<int, QByteArray> TaskModel::roleNames() const {
    return {
        { NameRole, "name" }
    };
}

void TaskModel::removeTask(int index) {
    if (index < 0 || index >= m_tasks.size()) return;

    beginRemoveRows(QModelIndex(), index, index);
    m_tasks.removeAt(index);
    endRemoveRows();
}
