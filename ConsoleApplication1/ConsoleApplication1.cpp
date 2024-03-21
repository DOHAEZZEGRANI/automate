#include <iostream>
#include <vector>
using namespace std;

class transition {
public:
    int etatd;
    char sym;
    int etata;
    transition() {
        etatd = 0;
        sym = 0;
        etata = 0;
    }
};

class Automate {
public:
    vector<char> alphabet;
    int etati;
    vector<int> etatf;
    vector<transition> t;

    Automate() {
        etati = 0;
    }

    Automate lecture() {
        Automate a;
        int l;
        cout << "donner le nombre d'alphabets" << endl;
        cin >> l;
        a.alphabet.resize(l);
        for (int i = 0; i < l; ++i) {
            cout << "entrer le " << i + 1 << "eme alphabet" << endl;
            cin >> a.alphabet[i];
        }

        cout << "donner le nombre d'etats finaux" << endl;
        cin >> l;
        a.etatf.resize(l);
        for (int i = 0; i < l; ++i) {
            cout << "entrer le " << i + 1 << "eme etat" << endl;
            cin >> a.etatf[i];
        }

        cout << "donner l'etat initial" << endl;
        cin >> a.etati;

        cout << "donner le nombre de transitions" << endl;
        cin >> l;
        a.t.resize(l);
        for (int i = 0; i < l; ++i) {
            cout << "Transition " << i + 1 << ":" << endl;
            cout << "Etat de depart : ";
            cin >> a.t[i].etatd;
            cout << "Symbole : ";
            cin >> a.t[i].sym;
            cout << "Etat d'arrivee : ";
            cin >> a.t[i].etata;
        }

        return a;
    }

    void affichage(Automate a) {
        cout << endl;
        cout << endl;
        cout <<"lautomate :" << endl;
        cout << "Alphabet : ";
        for (char c : a.alphabet) {
            cout << c << " ";
        }
        cout << endl;

        cout << "Etats finaux : ";
        for (int etat : a.etatf) {
            cout << etat << " ";
        }
        cout << endl;

        cout << "Etat initial : " << a.etati << endl;

        cout << "Transitions : " << endl;
        for (const transition& tr : a.t) {
            cout << "Etat de depart : " << tr.etatd << " - Symbole : " << tr.sym << " - Etat d'arrivee : " << tr.etata << endl;
        }
    }
    
    bool existe_trans(int d, char l) {
        for (const transition& tr : t) {
            if (tr.etatd == d && tr.sym == l) {
                return true;
            }
        }
        return false;
    }
    bool is_final(int f) {
        for (int tf : etatf) {
            if (tf == f) {
                return true;
            }
        }
        return false;
    }
    bool accepter(int etat_depart, char symbole) {
        
        bool estFinal = is_final(etat_depart);
        bool transExiste = existe_trans(etat_depart, symbole);

        return estFinal && transExiste;
    }




};

int main() {
    Automate a;
    a = a.lecture();
    a.affichage(a);

    int etat_depart,etat_final;
    char symbole;
    cout << "Entrez l'etat de depart : ";
    cin >> etat_depart;
    cout << "Entrez le symbole : ";
    cin >> symbole;

    if (a.existe_trans(etat_depart, symbole)) {
        cout << "La transition existe." << endl;
    }
    else {
        cout << "La transition n'existe pas." << endl;
    }
    cout << "Entrez l'etat final : ";
    cin >> etat_final;
    a.is_final(etat_final);
    if (a.accepter(etat_depart, symbole)) {
        cout << "La sequence est acceptee" << endl;
    }
    else {
        cout << "La sequence n'est pas acceptee" << endl;
    }

    return 0;
}

