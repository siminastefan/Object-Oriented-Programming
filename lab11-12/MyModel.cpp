#include "MyModel.h"
#include <string>


MyModel::~MyModel()
{
}

Dog MyModel::adopt(QModelIndex &index)
{
	int ind = index.row();
	Dog d = this->repo->get_elem(ind);
	this->repo->removeDog(d);
	emit dataChanged(index, index);
	return d;
}

void MyModel::addto(Dog d)
{
	this->repo->addDog(d);
	emit dataChanged(index(this->rowCount()), index(this->rowCount()));

}

int MyModel::rowCount(const QModelIndex & parent) const
{
	return this->repo->get_size();
}

QVariant MyModel::data(const QModelIndex & index, int role) const
{
	int row = index.row();

	if (role == Qt::DisplayRole)
	{
		Dog d = this->repo->getDogs()[row];
		std::string age = std::to_string(d.getAge());
		return QString::fromStdString(d.getBreed() + ", " + d.getName() + ", " + age);
	}
	return QVariant();
}
