#include <iostream>
using namespace std;
class Frunza
{
    private :
        string culoare;
    public:
        Frunza(const string &c):
            culoare(c)
            {}
        void setCuloare(const string &cul)
        {
            culoare=cul;
        }
        string getCuloare()
        {
            return culoare;
        }
};
class Fruct
{

private:
    string nume;
    string culoare;
    int nrEtapeCoacere;
    int index;
    int *frunze;
    Frunza *frunza; //->referinta la un obiect de tip frunza

    public:
        Fruct(const string &nume, const string &culoare, const int &nrEtapeCoacere) : //constructor parametrizat => ajuta la initializarea membrilor clasei
                                                                                    nume(nume),
                                                                                    culoare(culoare),
                                                                                    nrEtapeCoacere(nrEtapeCoacere),
                                                                                    index(0),
                                                                                    frunza(new Frunza("verde"))
        {
            // cout << ("\tCreare " + nume + "\n\n");
        }
        Fruct(const Fruct &fruct)
        { //copy contructor
            nume = fruct.nume;
            culoare = fruct.culoare;
            nrEtapeCoacere = fruct.nrEtapeCoacere;
        }
        Frunza &getFrunza(){
            
            return *frunza;
        }
        Fruct InlocuiesteGresit(const Frunza &f)
        {
            delete(frunza);
            frunza=new Frunza(f);
            return *this;


        }
        Fruct InlocuiesteCorect(const Frunza &f)
        {
            if(&getFrunza()==&f)
            {
                cout<<("Refera acelasi obiect!\n");
                return *this;
            }
            delete(frunza);
            frunza=new Frunza(f);
            return *this;

        }
          Fruct InlocuiesteCorectDoi(const Frunza &f)
        {
            
            Frunza *frunzaCopy=frunza;
            frunza=new Frunza(f);
            delete(frunzaCopy);
            return *this;

        }
        Fruct &operator=(const Fruct &)
        {
             cout << ("\t\t Assignment operator \n\n");
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
        void setFrunza(const string &cul){
            (*frunza ).setCuloare(cul);
        }

};
class FructTropical:Fruct{
    private :
         string zona;
    public :

        FructTropical (const Fruct &fruct, const string& zona ):
            Fruct(fruct),
            zona(zona)
            {};
        FructTropical (const FructTropical &f):
        
            Fruct(f),
            zona(f.zona)
        {}
        FructTropical &operator=(const FructTropical &f)
        {
            
            Fruct::operator=(f);
            zona=f.zona;
            return *this;
        }
        
};
int main()
{


    Fruct fruct = Fruct("mar", "galben", 3);
    cout << ("========================Assignment operators======================\n\n");
    
        int etape,i;
        etape=3; //->assignment
        i=0;     //->assignment
        while(i<etape)
        {
             fruct.coacere();
             i++;
        }
        Fruct fruct2=Fruct("mar", "galben", 3);
        fruct2=fruct; //-->assignment operator



     cout << ("================================================================\n\n");

    cout << ("\n\n\n======================== Assignment to self =====================\n\n");
        //////////////////////// CAZ GRESIT /////////////////////////////////////////////////
        // Frunza &f1=fruct2.getFrunza(); //-->referinta la acelasi obiect
        // f1.setCuloare("rosu"); //-->Setam alta culoare pentru obiectul frunza referit atat de f1, cat si de fruct2.frunza
        
        // fruct2=fruct2.InlocuiesteGresit(f1); //-->apelam functia de inlocuire a frunzai fin fruct cu alta. In acest caz, referinta e spre acelasi obiect
        
        // cout << ("Culoarea frunzei fructului 2 este "+fruct2.getFrunza().getCuloare()+"\n\n");
        // cout << ("Culoarea frunzai f1 este "+f1.getCuloare()+"\n\n");
        ////////////////////////////////////////////////////////////////////////////////////////

         //////////////////////// CAZ CORECT 1 //////////////////////////////////////////////////
        Frunza &f1=fruct2.getFrunza(); //-->referinta la acelasi obiect
        f1.setCuloare("rosu"); //-->Setam alta culoare pentru obiectul frunza referit atat de f1, cat si de fruct2.frunza
        
        fruct2=fruct2.InlocuiesteCorect(f1); //-->apelam functia de inlocuire a frunzai fin fruct cu alta. In acest caz, referinta e spre acelasi obiect
        
        cout << ("Culoarea frunzei fructului 2 este "+fruct2.getFrunza().getCuloare()+"\n\n");
        cout << ("Culoarea frunzai f1 este "+f1.getCuloare()+"\n\n");
        //////////////////////// CAZ CORECT 1 //////////////////////////////////////////////////
        
        //////////////////////// CAZ CORECT 2 //////////////////////////////////////////////////
        // Frunza &f1=fruct2.getFrunza(); //-->referinta la acelasi obiect
        // f1.setCuloare("rosu"); //-->Setam alta culoare pentru obiectul frunza referit atat de f1, cat si de fruct2.frunza
        
        // fruct2=fruct2.InlocuiesteCorectDoi(f1); //-->apelam functia de inlocuire a frunzai fin fruct cu alta. In acest caz, referinta e spre acelasi obiect
        
        // cout << ("Culoarea frunzei fructului 2 este "+fruct2.getFrunza().getCuloare()+"\n\n");
        //////////////////////// CAZ CORECT 2 //////////////////////////////////////////////////
 
    
    cout << ("================================================================\n\n");

    cout << ("======================== Copy all parts of an object=============\n\n");
    
       FructTropical ft=FructTropical(fruct, "lamaie");
       FructTropical ft2(ft);





     cout << ("================================================================\n\n");

}