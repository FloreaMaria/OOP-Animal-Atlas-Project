#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <string>
#include <exception>
#include <typeinfo>



//using namespace std;


class Exceptie : public std :: exception
{
    public:
        Exceptie() noexcept{}
        Exceptie(const Exceptie&) noexcept = default;
        Exceptie& operator = (const Exceptie&) noexcept = default;

        virtual const char* what() const noexcept{ return "Invalid value\n";}

        virtual ~Exceptie() noexcept = default;


};



class Animale
{
    std :: string home;
    std :: string WayOfReproduction;
    static double oxigen;

    public:
        Animale();
        Animale(std :: string home, std :: string reproduction);
        Animale(const Animale&);
        virtual ~Animale() = default;
        virtual void Display() = 0;

    static double getOxigen(){
        return oxigen;
    }

    void ReduceO2(){
        oxigen  = oxigen - 0.00000000000001;
    }

    static void OxigenRamas(){
        std :: cout << "Procentaj oxigen : ";
        std ::cout << std :: fixed << std :: setprecision(16) << Animale ::getOxigen() << " %\n";
    }

    std :: string getHome() const{
        return this -> home;
    }

    std :: string getRepr() const{
        return this -> WayOfReproduction;
    }

    void setHome(std :: string newhome){
        this -> home = newhome;
    }

    void setRepr(std :: string newWay){
        this -> WayOfReproduction = newWay;
    }

    Animale& operator = (const Animale&);
    friend std :: istream& operator >> (std :: istream&, Animale&);
    friend std :: ostream& operator << (std :: ostream&, const Animale&);

};


double Animale :: oxigen = 21;

Animale :: Animale() : home("Earth"), WayOfReproduction("None"){
    ///
}

Animale :: Animale(std ::  string newhome, std :: string newRepr) : home(newhome), WayOfReproduction(newRepr){
    ///
}

Animale ::  Animale(const Animale& A) : home(A.home), WayOfReproduction(A.WayOfReproduction){
    ///
}

Animale& Animale :: operator = (const Animale &A){

    if(this != &A)
        {
            this -> home = A.home;
            this -> WayOfReproduction = A.WayOfReproduction;
        }
    return *this;
}


std :: istream& operator >> (std :: istream& f, Animale& A){

    std :: string H, R;
    f >> H >> R;
    A.setHome(H);
    A.setRepr(R);
    return f;
}


std :: ostream& operator << (std :: ostream& c, const Animale& B){

    c << B.home <<  " " << B.WayOfReproduction << "\n";
    return c;

}


class Vertebrate : public Animale
{
    /// bool vertebra
    public:

        Vertebrate();
        Vertebrate(std :: string casa, std :: string Repr);
        Vertebrate(const Vertebrate &);
        virtual ~Vertebrate() = default;
        void Display();


        Vertebrate& operator = (const Vertebrate&);
        friend std :: istream& operator >> (std :: istream&, Vertebrate &);
        friend std :: ostream& operator << (std :: ostream&, Vertebrate &);


};


Vertebrate :: Vertebrate() : Animale(){
    //ctor
}

Vertebrate :: Vertebrate(std :: string casa, std :: string Repr) : Animale(casa, Repr){
    ///
}

Vertebrate :: Vertebrate(const Vertebrate & V) : Animale(V){
    ///
}


void Vertebrate :: Display(){

    std :: cout << "Mediu : " <<  getHome() << "\n" << "Reproducere : " << getRepr() <<"\n";
}


Vertebrate& Vertebrate :: operator = (const Vertebrate& V){

    if(this != &V)
        this -> Animale :: operator = (V);
    return *this;

}

std :: istream& operator >> (std :: istream&f, Vertebrate& V){

    std :: string casa, repr;
    std :: cout << "Specificatii vertebrata : \n";
    std :: cout << "Mediu : ";
    f >> casa;
    std :: cout << "Reproducere : ";
    f >> repr ;
    V.setHome(casa);
    V.setRepr(repr);
    //V.setVertebra(v);
    return f;
}

std :: ostream& operator << (std :: ostream& c, Vertebrate & V){

        c << "Specificatii : \n";
        V.Display();
        return c;

}




class Nevertebrate : public virtual Animale
{

    public:

        Nevertebrate();
        Nevertebrate(std :: string casa, std :: string R);
        Nevertebrate(const Nevertebrate&);
        virtual ~Nevertebrate()= default;
        void Display();
        Nevertebrate& operator = (const Nevertebrate&);
        friend std :: istream& operator >> (std :: istream&, Nevertebrate&);
        friend std :: ostream& operator << (std :: ostream&, Nevertebrate&);

};


Nevertebrate :: Nevertebrate() : Animale()
{
    ReduceO2();
    //ctor
}

Nevertebrate :: Nevertebrate(std :: string casa, std :: string R) : Animale(casa, R)
{
   ReduceO2();
}

Nevertebrate :: Nevertebrate (const Nevertebrate& N) : Animale(N)
{

}

void Nevertebrate :: Display()
{
    std ::  cout << "Mediu : " << getHome() << "\n" << "Reproducere : " << getRepr() << "\n";
}


Nevertebrate & Nevertebrate :: operator = (const Nevertebrate& N)
{
    if(this != &N)
    {
        this -> Animale :: operator = (N);
    }
    return *this;
}


std :: istream& operator >> (std :: istream& f, Nevertebrate& N)
{
    std :: string H, R;
    std :: cout << "Specificatii nevertebrata : \n";
    std :: cout << "Mediu : ";
    f >> H;
    std :: cout << "Reproducere : ";
    f >> R;
    N.setHome(H);
    N.setRepr(R);
    return f;
}

std :: ostream& operator << (std :: ostream& d, Nevertebrate& N)
{
    d << "Specificatii : \n";
    N.Display();
    return d;
}


class Mamifere : public Vertebrate
{
    std :: string alimentatie;

    public:
        Mamifere();
        Mamifere(std :: string home, std :: string repr, std :: string alimentatie);
        Mamifere(const Mamifere&);
        virtual ~Mamifere() = default;
        void Display();

        std :: string getAlimentatie() const{

            return this -> alimentatie;
        }

        void setAlimentatie(std :: string alimentatie_noua){

            this -> alimentatie = alimentatie_noua;
        }

        Mamifere& operator = (const Mamifere&);
        friend std :: istream& operator >> (std :: istream&, Mamifere&);
        friend std :: ostream& operator << (std :: ostream&, Mamifere&);

};


Mamifere :: Mamifere() : Vertebrate(), alimentatie("Unknown"){
    ReduceO2();
}

Mamifere :: Mamifere(std :: string casa, std :: string repr, std :: string alimentatie) :  Vertebrate(casa, repr), alimentatie(alimentatie){
    ReduceO2();
}

Mamifere :: Mamifere(const Mamifere& M) : Vertebrate(M), alimentatie(M.alimentatie){
    ///
}

void Mamifere :: Display(){

    Vertebrate :: Display();
    std :: cout << "Alimentatie : " << getAlimentatie() << "\n";
}

Mamifere& Mamifere :: operator = (const Mamifere& M){

    if( this != &M)
    {
        this -> Animale :: operator = (M);
        this -> Vertebrate :: operator = (M);
        this -> alimentatie = M.alimentatie;
    }
    return *this;
}

std :: istream& operator >> (std :: istream& f, Mamifere& M){

    std :: string H, R, alimentatie;
    std :: cout << "Specificatii mamifer : \n";
    std :: cout << "Mediu : ";
    f >> H;
    std :: cout << "Reproducere : ";
    f >> R;
    std :: cout << "Tip de alimentatie(omnivor, carnivor, ierbivor) : ";
    f >> alimentatie;
    M.setHome(H);
    M.setRepr(R);
    M.setAlimentatie(alimentatie);
    return f;
}
std :: ostream& operator << (std :: ostream& c, Mamifere & M){

     c << "Specificatii :  \n" ;
     M.Display();
     return c;
}



class Reptile : public Vertebrate
{
    std :: string veninos;

    public:

        Reptile();
        Reptile(std :: string casa, std :: string repr, std :: string venin);
        Reptile(const Reptile&);
        virtual ~Reptile() = default;
        void Display();

        std :: string getVenin() const
        {
            return this -> veninos;
        }
        void setVenin(std :: string nouv)
        {
            this -> veninos = nouv;
        }

        Reptile& operator = (const Reptile&);
        friend std :: istream& operator >> (std :: istream&, Reptile&);
        friend std :: ostream& operator << (std :: ostream&, Reptile&);

};




Reptile :: Reptile() : Vertebrate(), veninos("Nu"){

    ReduceO2();
}

Reptile :: Reptile(std :: string casa, std :: string repr, std :: string venin) : Vertebrate(casa, repr), veninos(venin){

    ReduceO2();
}

Reptile :: Reptile(const Reptile& R) : Vertebrate(R), veninos(R.veninos){
    ///
}

void Reptile :: Display(){

    Vertebrate :: Display();
    std :: cout << "Veninos : " << getVenin() << "\n";
}

Reptile& Reptile :: operator = (const Reptile& R){

    if(this != &R)
    {
        this -> Animale :: operator = (R);
        this -> Vertebrate :: operator = (R);
        this -> veninos = R.veninos;
    }
    return *this;
}

std :: istream& operator >> (std :: istream& f, Reptile & R){

    std :: string home, repr;
    double venin;
    std :: cout << "Specificatii reptila : \n";
    std :: cout << "Mediu : ";
    f >> home;
    std :: cout << "Reproducere : ";
    f >> repr;
    std :: cout <<"Inserati 1 pentru veninos, 0 pentru neveninos : ";
    f >> venin;
    if(venin == 1)
        R.setVenin("Da");
    else
        R.setVenin("Nu");

    R.setHome(home);
    R.setRepr(repr);

    return f;
}
std :: ostream& operator << (std :: ostream& c, Reptile& R)
{
    c << "Specificatii : ";
    R.Display();
    return c;
}




class Pasari : public Vertebrate
{
    int dimensiune_aripi;
    double viteza_zbor;

    public:

        Pasari();
        Pasari(std :: string casa, std :: string repr, int dimensiune_aripi, double viteza_zbor);
        Pasari(const Pasari&);
        virtual ~Pasari() = default;
        void Display();

        int getDimensiune() const{
            return this -> dimensiune_aripi;
        }

        void setDimensiune(int noudim){
            this -> dimensiune_aripi = noudim;
        }

        double getViteza() const{
            return this -> viteza_zbor;
        }

        void setViteza(double nouv){
            this -> viteza_zbor = nouv;
        }

        Pasari& operator = (const Pasari&);
        friend std :: istream& operator >> (std :: istream&, Pasari&);
        friend std :: ostream& operator << (std :: ostream&, Pasari&);

};

Pasari :: Pasari() : Vertebrate(),  dimensiune_aripi(0), viteza_zbor(0){
    ReduceO2();
}

Pasari :: Pasari(std :: string casa, std :: string repr, int dimensiune_aripi, double viteza_zbor) :  Vertebrate(casa, repr), dimensiune_aripi(dimensiune_aripi), viteza_zbor(viteza_zbor){
    ReduceO2();
}

Pasari :: Pasari(const Pasari& P) :  Vertebrate(P), dimensiune_aripi(P.dimensiune_aripi), viteza_zbor(P.viteza_zbor){
    ///
}

void Pasari :: Display(){

    Vertebrate ::  Display();
    std :: cout << "Dimensiune aripi(cm) : " << getDimensiune() << "\n" << "Viteza zbor(m/s) : " << getViteza() << "\n";
}


Pasari& Pasari :: operator = (const Pasari& P){

    if(this != &P)
    {
        this -> Animale :: operator = (P);
        this -> Vertebrate :: operator = (P);
        this -> dimensiune_aripi = P.dimensiune_aripi;
        this -> viteza_zbor = P.viteza_zbor;
    }
    return *this;
}

std :: istream& operator >> (std :: istream& f, Pasari& P){

    std :: string H, R;
    int dim;
    double speed;


    std :: cout << "Mediu : ";
    f >> H;
    std :: cout << "Reproducere : ";
    f >> R;
    std :: cout << "Dimensiune aripi : ";
    f >> dim;
    std :: cout << "Viteza in zbor : ";
    f >> speed;

    try{
        if(H.size() < 2)
            throw Exceptie();
    }catch(std :: exception & e)
    {
        std :: cout << e.what();
    }


    try{
        if(R.size() < 2)
            throw Exceptie();
    }catch(std :: exception & e)
    {
        std :: cout << e.what();
    }

    try{
        if(dim < 0)
            throw Exceptie();
    }catch(std :: exception & e)
    {
        std :: cout << e.what();
    }

    try{
        if(speed < 0)
            throw Exceptie();
    }catch(std :: exception & e)
    {
        std :: cout << e.what();
    }

    P.setHome(H);
    P.setRepr(R);
    P.setDimensiune(dim);
    P.setViteza(speed);
    return f;
}
std :: ostream& operator << (std :: ostream& c, Pasari & P){

     c << "Specificatii : \n";
     P.Display();
     return c;
}


class Pesti : public Vertebrate
{

    std :: string tip_inotatoare;
    int nr_inotatoare, dimensiune;
    bool rapitor;


    public:

        Pesti();
        Pesti(std :: string casa, std :: string tip_inotatoare, int nr_inotatoare, int dim, bool rapitor);
        Pesti(const Pesti&);
        virtual ~Pesti() = default;
        void Display();

        std :: string getInotatoare() const{
            return this -> tip_inotatoare;
        }

        void setInotatoare(std :: string tip_nou){
            this -> tip_inotatoare = tip_nou;
        }

        int getnrInotatoare() const{
            return this -> nr_inotatoare;
        }

        void setnrInotatoare(int nnou){

            this -> nr_inotatoare = nnou;
        }

        void setRapitor(bool a){

            this -> rapitor = a;
        }

        int getRapitor() const{

            return this -> rapitor;
        }

        void setDim(int dimnou){
            this -> dimensiune = dimnou;
        }
        int getDim() const{
            return this -> dimensiune;
        }


        Pesti& operator = (const Pesti&);
        friend std :: istream& operator >> (std :: istream&, Pesti&);
        friend std :: ostream& operator << (std :: ostream&, Pesti&);


};



Pesti :: Pesti() : Vertebrate(), tip_inotatoare("basic"), nr_inotatoare(0), dimensiune(0), rapitor(0){

    ReduceO2();
}

Pesti :: Pesti(std :: string casa, std :: string tip_inotatoare, int nr_inotatoare, int dim, bool r) :
    Vertebrate(casa, "eggs"), tip_inotatoare(tip_inotatoare), nr_inotatoare(nr_inotatoare),  dimensiune(dim), rapitor(r){

    ReduceO2();
}

Pesti :: Pesti(const Pesti & P) : Vertebrate(P), tip_inotatoare(P.tip_inotatoare), nr_inotatoare(P.nr_inotatoare),
        dimensiune(P.dimensiune), rapitor(P.rapitor){
    ///
}

void Pesti :: Display(){

    Vertebrate :: Display();
    std :: cout << "Tip inotatoare : " << getInotatoare() << "\n";
    std ::  cout << "Numar inotatoare : " << getnrInotatoare() << "\n" << "Dimensiune : " << getDim() << " cm \n";
    if(getRapitor())
        std :: cout << "Rapitor : DA\n";
    else
        std :: cout << "Rapitor : NU\n";
}

Pesti & Pesti :: operator = (const Pesti & P){

    if( this != &P)
    {
        this -> Animale :: operator = (P);
        this -> Vertebrate :: operator = (P);
        this -> nr_inotatoare = P.nr_inotatoare;
        this -> tip_inotatoare = P.tip_inotatoare;
        this -> rapitor = P.rapitor;
        this -> dimensiune = P.dimensiune;
    }
    return *this;
}


std :: istream& operator >> (std :: istream& f, Pesti& P){

    std :: string home, repr, tip_inotatoare;
    int nr_inotatoare, dimensiune;
    bool R;
    std :: cout << "Specificatii peste : \n";
    std :: cout << "Mediu : ";
    f >> home;
    std :: cout << "Reproducere : ";
    f >> repr;
    std :: cout << "Tip inotatoare : ";
    f >> tip_inotatoare;
    std :: cout << "Numar inotatoare : ";
    f >> nr_inotatoare;
    std :: cout << "Dimensiune(cm) : ";
    f >> dimensiune;
    std :: cout << "Rapitor :(0 - NU, 1 - DA) : ";
    f >> R;

    try{
        if(home.size() < 2)
            throw Exceptie();
    }catch(std :: exception &e){
        std :: cout << e.what() << " of Mediu\n";
    }

    try{
        if(repr.size() < 2)
            throw Exceptie();
    }catch(std :: exception &e){
        std :: cout << e.what() << " of Reproducere\n";
    }

    try{
        if(tip_inotatoare.size() < 2)
            throw Exceptie();
    }catch(std :: exception &e){
        std :: cout << e.what() << " of tip_inotatoare\n" ;
    }

    try{
        if(nr_inotatoare < 2)
            throw Exceptie();
    }catch(std :: exception &e){
        std :: cout << e.what() << " of nr_inotatoare\n";
    }

    try{
        if((R != 0) && (R != 1))
            throw Exceptie();
    }catch(std :: exception &e){
        std :: cout << e.what() << " of Rapitor\n";
    }


    P.setRapitor(R);
    P.setHome(home);
    P.setRepr(repr);
    P.setInotatoare(tip_inotatoare);
    P.setnrInotatoare(nr_inotatoare);
    P.setDim(dimensiune);
    return f;
}

std :: ostream& operator << ( std :: ostream& c, Pesti& P)
{
    c << "Specificatii : \n";
    P.Display();
    return c;
}


template<class T> class AtlasZoologic;
template<class T> std :: ostream& operator <<(std :: ostream&,AtlasZoologic<T>&);
template<class T> std :: istream& operator >>(std :: istream&,AtlasZoologic<T>&);


template <typename T>
class AtlasZoologic
{
    int nr_animale;
    std :: vector <T*> Animal;

public:

    AtlasZoologic() : nr_animale(0)
    {
        ///
    }

    AtlasZoologic(int nr, std :: vector <T*> R) : nr_animale(nr), Animal(R)
    {
        ///
    }

    AtlasZoologic(const AtlasZoologic& R) : nr_animale(R.nr_animale), Animal(R.Animal)
    {
        ///
    }

    virtual ~AtlasZoologic()
    {
        for(auto el : Animal)
            delete el;
        Animal.clear();
    };

    int get_nr() const
    {
        return nr_animale;
    }

    void set_nr(int n)
    {
        this -> nr_animale = n;
    }

    void setVector(std :: vector <T*> L)
    {
        this -> Animal = L;
    }

    std :: vector <T*> getVector() const
    {
        return this -> Animal;
    }

    AtlasZoologic<T>& operator += (T *A)
    {
            nr_animale ++;
            Animal.push_back(A);
        return *this;
    }

    AtlasZoologic <T>& operator = (const AtlasZoologic& Z)
    {
        if(this != &Z)
        {
            this -> nr_animale = Z.nr_animale;
            this -> Animal = Z.Animal;
        }
        return *this;
    }
    void Display()
    {
        std :: cout << "\nNumarul de animale : " << get_nr() << "\n";
        std :: vector < T*> V = getVector();

        for(auto it : V)
        {
            if(typeid(*it) == typeid(Nevertebrate))
                std :: cout << "Fisa obervatie -> Nevertebrata : \n";
            if(typeid(*it) == typeid(Vertebrate))
                std :: cout << "Fisa observatie -> Vertebrata : \n";
            if(typeid(*it) == typeid(Pesti))
                std :: cout << "Fisa observatie -> Peste : \n";
            if(typeid(*it) == typeid(Pasari))
                std :: cout << "Fisa observatie -> Pasare : \n";
            if(typeid(*it) == typeid(Reptile))
                std :: cout << "Fisa observatie -> Reptila : \n";
            if(typeid(*it) == typeid(Mamifere))
                std :: cout << "Fisa observatie -> Mamifer : \n";
            it -> Display();
        }

    }


    friend std :: istream& operator >> <>(std :: istream&f, AtlasZoologic <T> &);
    friend  std :: ostream& operator<< <>(std :: ostream& c, AtlasZoologic <T> & );

};
template <class T>

std :: istream& operator >> (std :: istream & f, AtlasZoologic <T> &A)
{
    int nr_animale, p, r, nounr;
    std :: cout << "Numar animale : ";
    f >> nr_animale;
    nounr = nr_animale;
    try
    {
        if(nr_animale <= 0)
            throw Exceptie();
    }
    catch (std :: exception &e)
    {
        std :: cout << e.what();

    }

    std :: vector <T*> V;

    while(nr_animale > 0)
    {
        std :: cout << "Alege un tip de animal(0 - Nevertebrat, 1 - Vertebrat) : ";

        f >> p;
        if(p == 0)
        {
            Nevertebrate * N = new Nevertebrate;
            f >> *N;
            V.push_back(N);
            nr_animale --;
        }
        if(p == 1)
        {

            std :: cout <<  "Alege o vertebrata (1 - Pasare, 2 - Peste, 3 - Reptila, 4 - Mamifer) : \n";
            f >> r;
            switch (r)
            {
            case 1:
            {

                Pasari * P = new Pasari;
                f >> *P;
                V.push_back(P);
                nr_animale --;
                break;
            }
            case 2 :
            {
                Pesti * p = new Pesti();
                f >> (*p);
                V.push_back(p);
                nr_animale--;
                break;
            }
            case 3 :
            {
                Reptile *r = new Reptile();
                f >> (*r);
                V.push_back(r);
                nr_animale -- ;
                break;
            }
            case 4 :
            {
                Mamifere *m  = new Mamifere();
                f >> (*m);
                V.push_back(m);
                nr_animale--;
                break;
            }

            default:
            {
                try
                {
                    throw Exceptie();
                }
                catch(std :: exception & e)
                {
                    std :: cout << e.what();
                }
                break;
            }
            }
        }
    }

    A.set_nr(nounr - nr_animale);
    A.setVector(V);
    return f;
}


template <class T>
std :: ostream& operator << (std :: ostream & c, AtlasZoologic <T> &A)
{
    c << "\nNumarul de animale : " << A.get_nr() << "\n";
    std :: vector < T*> V = A.getVector();

    for(auto it : V)
    {
        if(typeid(*it) == typeid(Nevertebrate))
           std ::  cout << "Fisa obervatie -> Nevertebrata : \n";
        if(typeid(*it) == typeid(Vertebrate))
            std :: cout << "Fisa observatie -> Vertebrata : \n";
        if(typeid(*it) == typeid(Pesti))
            std :: cout << "Fisa observatie -> Peste : \n";
        if(typeid(*it) == typeid(Pasari))
            std :: cout << "Fisa observatie -> Pasare : \n";
        if(typeid(*it) == typeid(Reptile))
           std :: cout << "Fisa observatie -> Reptila : \n";
        if(typeid(*it) == typeid(Mamifere))
            std :: cout << "Fisa observatie -> Mamifer : \n";
        it -> Display();
    }
    return c;
}





template <>
class AtlasZoologic<Pesti>
{
    int nrPestiRapitori, nrPestiBuni;
    std :: vector <Pesti*> V;
public :

    AtlasZoologic() : nrPestiRapitori(0), nrPestiBuni(0)
    {
        ///
    };

    AtlasZoologic(int nrP, int nrR) : nrPestiRapitori(nrR), nrPestiBuni(nrP)
    {
        ///
    }

    AtlasZoologic (const AtlasZoologic & A)
    {
        if(this != &A)
        {
            this -> nrPestiBuni = A.nrPestiBuni;
            this -> nrPestiRapitori = A.nrPestiRapitori;
            for(unsigned int i = 0; i < A.V.size(); i++)
                V.push_back(A.V[i]);
        }
    }

    int getPestiR()const
    {
        return this -> nrPestiRapitori;
    }

    int getPestiBuni()const
    {

        return this -> nrPestiBuni;
    }

    void setPestiR(int nou)
    {
        this -> nrPestiRapitori = nou;
    }
    void setPestiBuni(int nou)
    {
        this -> nrPestiBuni = nou;
    }

    std :: vector <Pesti*> getV()
    {
        return this -> V;
    }

    void setV(std :: vector <Pesti*> Nou)
    {
        this -> V = Nou;
    }


    AtlasZoologic <Pesti> & operator += (Pesti * P)
    {
        std :: cout << "Adaugare peste nou \n";
        V.push_back(P);
        if(P -> getRapitor())
        {
            if(P -> getDim() >= 100)
                nrPestiBuni ++;
        }
        return *this;
    };

    AtlasZoologic<Pesti> & operator = (AtlasZoologic <Pesti> & P)
    {
        nrPestiRapitori = P.nrPestiRapitori;
        nrPestiBuni = P.nrPestiBuni;
        for(unsigned int i = 0; i < P.V.size(); i++)
            V.push_back(P.V[i]);
        return *this;

    };
    void AfisareRapitoriMari()
    {
        std :: cout << "Numarul pestilor rapitori cu lungimea mai mare de 100 : ";
        std :: cout << nrPestiBuni << "\n";
    }

    friend std :: istream& operator >> (std :: istream& f, AtlasZoologic <Pesti> & P)
    {
        int nr;
        std :: cout << "Introduceti nr de pesti : \n";
        f >> nr;
        std :: cout << "Introduceti fisele de observatie pentru " << nr << " pesti\n";
        for(int i = 0; i < nr; i++)
        {
            Pesti * T = new Pesti;
            std :: cin >> *T;
            P.V.push_back(T);
            if(T -> getRapitor())
            {
                P.nrPestiRapitori ++;
                if(T -> getDim() >= 100)
                    P.nrPestiBuni ++;
            }

        }
        return f;
    }

    friend  std :: ostream& operator << (std :: ostream& c, AtlasZoologic <Pesti>& P)
    {
        c << "Atlas Pesti : ";
        if(P.V.size() == 0)
            c << "gol\n";
        else
        {
            c << "\n";
            for(unsigned int i = 0; i < P.V.size(); i ++)
            {
                c <<"Pagina nr " <<  i + 1 << ": \n";
                P.V[i] -> Display();
            }
        }
        return c;

    }

    ~AtlasZoologic()
    {
        for(auto i : V)
            delete i;
        V.clear();
    }


};



void CitireAnimale()
{

    std :: list <Animale*> Lista;
    int n, nev;
    std :: cout << "Introduceti numarul de animale : ";

    if(std :: cin >> n)
    {
        while(n > 0)
        {
            std :: cout << "Alege un tip de animal (1 - nevertebrata, 2 - vertebrata) :\n";
            int p;
            std :: cin >> p;
            if(p == 1)
            {
                Nevertebrate * N = new Nevertebrate();
                std ::  cin >> (*N);
                Lista.push_back(N);
                n --;
            }
            else if(p == 2)
            {
                std :: cout << "Alege o vertebrata (1 - Pasare, 2 - Peste, 3 - Reptila, 4 - Mamifer) : \n";
                std :: cin >> nev;

                switch(nev)
                {
                case 1 :
                {
                    Pasari * p = new Pasari();
                    std :: cin >> (*p);
                    Lista.push_back(p);
                    n --;
                    break;
                }
                case 2 :
                {
                    Pesti * p = new Pesti();
                    std :: cin >> (*p);

                    Lista.push_back(p);
                    n--;
                    break;
                }
                case 3 :
                {
                    Reptile *r = new Reptile();
                    std :: cin >> (*r);
                    Lista.push_back(r);
                    n -- ;
                    break;
                }
                case 4 :
                {
                    Mamifere *m  = new Mamifere();
                    std :: cin >> (*m);
                    Lista.push_back(m);
                    n --;
                    break;
                }
                }
            }
        }
    }
    else
    {
        std ::  cout << "Wrong number!\n";
    }
    int i = 1;
    for(auto it : Lista)
    {
        std :: cout << "Animalul nr " << i << ": \n";
        i++;
        it -> Display();
    }

}

void Meniu()
{
    std :: cout << "MENIU :\n";
    std :: cout << "1 - Citire si afisare n animale\n";
    std :: cout << "2 - Citire atlas zoologic\n";
    std :: cout << "3 - Adaugare fisa observatie in atlas\n";
    std :: cout << "4 - Afisare atlas\n";
    std :: cout << "5 - Citire atlas pesti\n";
    std :: cout << "6 - Afisare numar pesti rapitori mai mari de 1 metru\n";
    std :: cout << "7 - Revenire meniu principal\n";
    std :: cout << "8 - Exit\n";
}









int main()
{
    int p;
    int ok = 0, animal, ok2 = 0;
    AtlasZoologic <Animale> A;
    AtlasZoologic<Pesti> P;
    do
    {
        Meniu();
        std :: cin >> p;
        if(p == 1)
            CitireAnimale();
        else if(p == 2)
        {
            ok = 1;
            std :: cin >> A;
        }
        else if(p == 3)
        {
            if(ok == 1)
            {
                std :: cout << "Introduceti ce fel de animal doriti sa adaugati in atlas\n";
                std :: cout << "1 - Nevertebrata, 2 - Vertebrata\n";
                std :: cin >> animal;
                if(animal == 1)
                {
                    Nevertebrate *N = new Nevertebrate;
                    std :: cin >> *N;
                    A += N;
                    std :: cout << "Adaugare efectuata cu succes!\n";
                }
                else if(animal == 2)
                {
                    int c;
                    std :: cout << "Introduceti ce vertebrata doriti sa adaugati in atlas\n";
                    std :: cout << "1 - Pasare, 2 - Peste, 3 - Reptila, 4 - Mamifer \n";
                    std :: cin >> c;
                    if(c == 1)
                    {
                        Pasari * p = new Pasari;
                        std :: cin >> *p;
                        A += p;
                        std :: cout << "Adaugare efectuata cu succes!\n";
                    }
                    else if(c == 2)
                    {
                        Pesti * l =  new Pesti;
                        std :: cin >> *l;
                        A += l;
                        std :: cout << "Adaugare efectuata cu succes!\n";
                    }
                    else if(c == 3)
                    {
                        Reptile *r =  new Reptile;
                        std :: cin >> *r;
                        A += r;
                        std :: cout << "Adaugare efectuata cu succes!\n";
                    }
                    else if(c == 4)
                    {
                        Mamifere  *m = new Mamifere;
                        std :: cin >> *m;
                        A += m;
                        std :: cout << "Adaugare efectuata cu succes!\n";
                    }
                    else
                    {
                        std :: cout << "Introduceti optiune valida!\n";
                        continue;
                    }
                }

            }
            else
            {
                std :: cout << "Nu ati citit un atlas inca!\n";
                continue;
            }
        }
        else if(p == 4)
        {
            if(ok == 1)
            {
                std :: cout << A;
            }
            else
            {
                std :: cout << "Nu ati citit un atlas inca!\n";
                continue;
            }
        }
        else if(p == 5)
        {
            ok2 = 1;
            std :: cin >> P;
        }
        else if(p == 6)
        {
            if(ok2 == 0)
                std :: cout << "Nu ati citit un atlas pentru pesti inca!\n";
            else
            {
                if(P.getPestiBuni() == 1)
                    std :: cout << "Exista 1 peste rapitor mai mare de 1 metru\n";
                if(P.getPestiBuni() == 0)
                    std :: cout << "Nu exista pesti rapitori mai mari de 1 metru in acest atlas\n";
                else
                    std :: cout << "Exista " << P.getPestiBuni() << " pesti rapitori mai mari de 1 metru in acest atlas\n";
            }

        }
        else if(p == 8)
        {
            break;
        }
        else
        {
            std :: cout << "Introduceti o optiune valida!\n";
            continue;
        }
    }
    while(true);

    return 0;
}
