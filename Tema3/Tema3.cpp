#include <iostream>
using namespace std;
#include <memory>
class Copac {
	private :
	bool utilizat;
	int cantitateApa;
	public:
	Copac(){};
	Copac(bool a, int b)
	{
		this->utilizat=a;
		this->cantitateApa=b;
	}
	void aflareCantitateApa()
	{
		cout<<"Cantitatea de apa ramasa: "<<cantitateApa;
		cout <<endl;
	}
	void setUtilizat(bool a)
	{
		this->utilizat=a;
	}
	bool aflareUtilizare()
	{
		if (this->utilizat)
		{
			cout<<"Apa copacului e utilizata de o alta frunza! "<<endl;
			return true;
		}
		else{
			cout<<"Apa copacului poate sa fie utilizate "<<endl;
			return false;
		}
	}
	void folosireApa(int a)
	{
		this->cantitateApa=this->cantitateApa-a;
	}

};
void utilizare(Copac &copac)
{
	copac.setUtilizat(true);

}
void terminareUtilizare(Copac &copac)
{
	copac.setUtilizat(false);

}
class Frunza
{
	private:
	Copac &copac;
	public:
	Frunza(Copac &c):
		copac(c){}
	
	void simbioza()
	{
		cout<<"Verificare daca copacul poate sa ofere apa"<<endl;
		if(copac.aflareUtilizare()==false)
		{
			cout<<"Frunza consuma apa pentru simbioza"<<endl;
			utilizare(copac);
			copac.folosireApa(30);
		}
		
	}
	void terminareSimbioza()
	{
		terminareUtilizare(copac);
		cout<<"Frunza termina simbioza"<<endl;
	}

};
class Fruct {
	private:
	string nume;
	int numarSeminte;

public:
	Fruct(int l, string b)
	{
		nume = b;
		numarSeminte = l;
	}

	void detaliiFRuct()
	{
		cout <<"Nume:" + nume + ", numar seminte: " << numarSeminte;
	}
};

int main()
{

	Copac resursaComuna (false, 100);
	Frunza *frunza1=new Frunza(resursaComuna);
	frunza1->simbioza();
	cout<<endl;
	Frunza *frunza2=new Frunza(resursaComuna);
	frunza2->simbioza();
	cout<<endl;
	frunza1->terminareSimbioza();
	cout<<endl;
	frunza2->simbioza();
	cout<<endl;


	cout<<"=================================== ITEM13 ==============================="<<endl;
	cout<<"================================== Unique_ptr ============================"<<endl;
	unique_ptr<Fruct> F1(new Fruct(10, "caspuna"));
    F1->detaliiFRuct() ; 
	cout <<endl;
 
    unique_ptr<Fruct> F2;
	F2=move(F1); //-> transfer ownership
    F2->detaliiFRuct() ;
	cout <<endl;
 
    //F1->detaliiFRuct();
	
	cout<<"================================== Shared_ptr ============================"<<endl;
	shared_ptr<Fruct> P1(new Fruct( 5,"mar"));
	P1->detaliiFRuct() ;
	cout <<endl;
	shared_ptr<Fruct> P2;
	P2 = P1;
	P2->detaliiFRuct() ;
	cout <<endl;
	P1->detaliiFRuct() ;
	cout <<endl;
	cout <<endl;
	cout<<P1.use_count()<<endl;
	return 0;
}
