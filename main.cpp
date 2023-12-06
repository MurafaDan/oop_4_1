#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Cladire
{
    protected:
        char adress[100];
        int nr_etaj;
        int nr_loc;
    public:
    // implicit
        Cladire () : nr_etaj(0), nr_loc(0){}

        Cladire(const Cladire &c)
        {
            strcpy(this -> adress, c.adress);
            this -> nr_etaj = c.nr_etaj;
            this -> nr_loc = c.nr_loc;
        }
        void afisare() {
            cout << "nr de locuitori";
        }
        // facem acces la membrii protected
        friend istream& operator>>(istream &in, Cladire &c)
        {
            cout << "Introdu adresa : ";
            in >> c.adress;
            cout << "Etaje : ";
            in >> c.nr_etaj;
            cout << "Nr de locuitori : ";
            in >> c. nr_loc;
            return (in);
        }
        friend ostream& operator<<(ostream &out, Cladire &c)
        {
            return out << "Adresa : " << c.adress << endl
            << "Etaje : " << c.nr_etaj << endl
            << "Nr de locuitori: " << c.nr_loc << endl;
        }
};

class Adm_cladire : public Cladire
{
    char admin[100];
    int nb_office;
    public:
        Adm_cladire() : nb_office(0){}
        Adm_cladire(const Adm_cladire &c)
        {
            strcpy(this -> admin, c.admin);
            this -> nb_office = c.nb_office;
        }
        friend istream& operator>>(istream &in, Adm_cladire &c)
        {
            cout << "Numele de admin: ";
            in >> c.admin;
            cout << "Nr de office : ";
            in >> c.nb_office;
            return (in);
        }
        friend ostream& operator<<(ostream &out, Adm_cladire &c)
        {
            return out << "Admin: " << c.admin << endl
            << "NR de office : " << c.nb_office << endl;
        }
};

class Loc_cladire : public Cladire
{
    char name_loc[100];
    int nb_cam;
    public:
        Loc_cladire() : nb_cam(0){}
        Loc_cladire(const Loc_cladire &c)
        {
            strcpy(this -> name_loc, c.name_loc);
            this -> nb_cam;
        }
        friend istream& operator>>(istream &in, Loc_cladire &c)
        {
            cout << "Numele de locuitor : ";
            in >> c.name_loc;
            cout << "Numarul camerei : ";
            in >> c.nb_cam;
            return (in);
        }
        friend ostream& operator<<(ostream &out, Loc_cladire &c)
        {
        return out << "Locuitor : " << c.name_loc << endl
        << "Numarul camerei : " << c.nb_cam << endl;
        }
};

int main()
{
    Cladire c1;
    Adm_cladire c2;
    Loc_cladire c3;
    Adm_cladire * c4 = new Adm_cladire ;
    c4->afisare();

    Cladire * c5 = new Cladire;
    Cladire(*c5).afisare();
    Cladire().afisare();

    Adm_cladire(*c4).afisare();

    cin >> c1;
    cin >> c2;
    cin >> c3;
    cout <<"\nCladire"<< endl;
    cout << c1;
    cout <<"\n Clardire administrativa"<< endl;
    cout << c2;
    cout <<"\ncladire de locuit"<< endl;
    cout << c3;
    return 0;
}
