#include "lab1112.h"
#include <QtWidgets/QApplication>
#include "MyGUIByHand.h"
#include "MyGUIWithCreator.h"
#include "MyModel.h"

class B
{
public:
	B() { std::cout << "B{}"; }
	virtual void print() {
		std::cout <<
			"B";
	}
	virtual ~B() { std::cout << "~B()"; }
};
class D : public B
{
public:
	D() { std::cout << "D{}"; }
	void print() override {
		std::cout <<
			"D";
	}
	virtual ~D() { std::cout << "~D()"; }
};

int main(int argc, char *argv[])
{
	/*QApplication a(argc, argv);

	lab1112 w;
	w.show();
	return a.exec();*/

	//QApplication a(argc, argv);

	//Repository* repo = new FileRepository{ "dogs.txt" };
	//Repository* adoption = new FileRepository{ "adoption.txt" };
	//RepoAdoption adop{};
	//MyModel *m1 = new MyModel{repo};
	//MyModel *m2 = new MyModel{ adoption };
	//Service serv(repo, adoption, DogValidator {});

	////MyGUIByHand w{ serv };
	////MyGUIWithCreator w{ serv };
	//lab1112 w{ serv,m1,m2};
	//w.show();

	//return a.exec();

	B* b[] = { new B{}, new D{} };
	b[0]->print();
	b[1]->print();
	delete b[0];
	delete b[1];
	return 0;
}
