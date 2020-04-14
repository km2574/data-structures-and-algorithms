#include<iostream>
#include<cstring>
using namespace  std;


class Car{
private:
	int price;
public:
	int model_no;
	char* name= NULL;

	//constructor
	Car(){
		cout << "I m constructor \n";
	}

	//constructor with parameters
	Car(int p,int mn,char const* n){
		price = p;
		model_no = mn;
		int len = strlen(n);
		name = new char[len+1];
		strcpy(name,n);
		cout << "I am constructor with parameters \n";

	}

	//copy constructor
	Car(Car& Z)
	{
		price = Z.price;
		model_no = Z.model_no;
		name = new char[strlen(Z.name)+1];
		strcpy(name,Z.name);
		cout << "my deep copy fn \n";
	}
	void setName(char const *n)
	{
		if (name == NULL)
		{
			name = new char[strlen(n)+1];
			strcpy(name,n);
		}
	}
	void setPrice(int p)
	{
		price = p;
	}
	void getPrice()
	{
		cout << price << endl;
	}
	void printClassData(){
		cout << price << endl;
		cout << model_no << endl;
		cout << name << endl;
	}
};


int main()
{
	//Car A;
	// A.setPrice(1000);
	// A.getPrice();



	//Car B(1010,5001,"Maruti");
	//B.printClassData();

	//Car C(B);
	// C.printClassData();

	/*Car D;
	D.setPrice(100);
	D.setName("Audi");
	D.model_no = 5001;
	D.printClassData();
	cout << "---------------------------- \n";*/
	Car E(200,5002,"BMW");
	E.printClassData();
	cout << "---------------------------- \n";
	Car F(E);
	F.name[0] = 'K';
	E.printClassData();
	F.printClassData();
}