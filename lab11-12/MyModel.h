#pragma once
#include <QAbstractListModel>
#include "Repository.h"

class MyModel : public QAbstractListModel
{
private:
	Repository* repo;
public:
	MyModel(Repository* _repo) : repo{ _repo } {}
	~MyModel();

	Dog adopt(QModelIndex &index);
	void addto(Dog d);

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

