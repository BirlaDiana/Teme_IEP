#include <iostream>
using namespace std;
class Arbore{
    protected:
        Arbore(){};
        ~Arbore(){};

    private:
        Arbore(const Arbore& arb);
        Arbore& operator=(const Arbore& arb);

};

class PomFructifer: Arbore {

};

class Fruct
{

private:
    string nume;
    string culoare;
    int nrEtapeCoacere;
    int index;

    public:
        Fruct(const string &nume, const string &culoare, const int &nrEtapeCoacere) : //constructor parametrizat => ajuta la initializarea membrilor clasei
                                                                                    nume(nume),
                                                                                    culoare(culoare),
                                                                                    nrEtapeCoacere(nrEtapeCoacere),
                                                                                    index(0)
        {
            cout << ("\tCreare " + nume + "\n\n");
        }
        Fruct(const Fruct &fruct)
        { //copy contructor
            nume = fruct.nume;
            culoare = fruct.culoare;
            nrEtapeCoacere = fruct.nrEtapeCoacere;
        }
        Fruct &operator=(const Fruct &)
        {
            return *this;
        }
        void coacere()
        {
            if (index < nrEtapeCoacere)
            {
                index++;
                cout << ("\t\t\tCoacere " + nume + "\n\n");
            }
        }
        ~Fruct()
        {
            if (index == nrEtapeCoacere)
            {
                cout << ("S-a copt si cade\n\n\n");
            }
            else
            {
                cout << ("Este cules neprevazut, inainte sa se coaca complet\n\n\n");
            }
        }
        string getNume()
        {
            return nume;
        }
        void setNume(const string &n)
        {
            nume = n;
        }

};
int main()
{
    cout << ("=========Verificam fuctionalitate constructor/destructor===========\n\n");
    {
        int i=0; //initializare manuala 
        
        //Apel constructor
        Fruct f = Fruct("mar", "rosu", 4);

        while(i<4){
            f.coacere();
            i++;
        }
    }
    cout << ("================================================================\n\n");
    
    cout << ("=======================Verificam copy constructor===============\n\n");
    Fruct fruct1 = Fruct("mar", "galben", 3);
    Fruct fruct2(fruct1);

    cout << ("\t Numele fructului 2 se schimba \n\n");
    fruct2.setNume("caspune");

    cout << ("Nume fruct 1: " + fruct1.getNume() + "\n\n");
    cout << ("Nume fruct 2: " + fruct2.getNume() + "\n\n");
    cout << ("================================================================\n\n");
    
    
    cout << ("=====================Verificam copy operator======================\n\n");
    Fruct fruct3=Fruct("capsune","rosu",5);
    fruct3=fruct2;
    fruct3.setNume("banana");
    cout << ("\t Numele fructului 3 se schimba \n\n");

    cout << ("Nume fruct 3: " + fruct3.getNume() + "\n\n");
    cout << ("Nume fruct 2: " + fruct2.getNume() + "\n\n");
    cout << ("================================================================\n\n");
    
    PomFructifer pom;
    //PomFructifer pom1(pom); // eroare, deoarece copy constructor e sters
    //pom=pom1;//eroare, copy operator e sters

}