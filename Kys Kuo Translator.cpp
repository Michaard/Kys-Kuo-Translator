// Translator jezyka polskiego na Kys Kuo (Ludu Lip)
// Wszystkie slowa jezyka odpowiadaja slowom jezyka polskiego,
// jednak litery jezyka Kys Kuo odpowiadaja literom na lewo (na klawiaturze QWERTY)
// od liter slow polskich z drobnymi modyfikacjami:
// c = z (jezeli jest pierwsza litera slowa)
// c = ' (jezeli wystepuje w srodku slowa)
// c = [brak] (jezeli wystepuje na koncu slowa)
// k = q
// w = p
// e = eve
// y = yt

// UWAGI!
// - W jednym slowie moze wystapic jedynie jeden apostrof.
// - Jezeli w slowie przy przekladzie jakas litera pojawi sie podwojnie (w sasiedztwie samej siebie)
//   nalezy oddzielic te litery apostrofem.
// - Jezeli w slowie jest juz jeden apostrof i pojawia sie zdublowana litera:
//   dubel skasowac.

#include <iostream>
#define ALPHABET_SIZE 22

using namespace std;

class KysKuoTranslator{
private:
    string alphabetPLcapital;
    string alphabetPLsmall;
    string alphabetKKcapital;
    string alphabetKKsmall;
public:
    KysKuoTranslator(){
        this->alphabetPLcapital="ABDFGHJMNPQRSTVXZWKIOUYL";
        this->alphabetPLsmall="abdfghjmnpqrstvxzwkiouyl";
        this->alphabetKKcapital="AVSDFGHNBOPEARCZMPQUIYTK";
        this->alphabetKKsmall="avsdfghnbopearczmpquiytk";
    }
    string translationPLtoKK(string);
};
string KysKuoTranslator::translationPLtoKK(string wordPL){
    string outputWord="";
    char letter;
    bool apostroph=true;
    int wordLength=wordPL.length();
    for(int i=0;i<wordLength;i++){
        letter=wordPL[i];
        for(int j=0;ALPHABET_SIZE;j++){
            if(letter=='C'){
                if(i==0)
                    outputWord+='Z';
                else if(i!=wordLength-1 && apostroph){
                    outputWord+='\'';
                    apostroph=false;
                }
                break;
            }
            else if(letter=='c'){
                if(i==0)
                    outputWord+='z';
                else if(i!=wordLength-1 && apostroph){
                    outputWord+='\'';
                    apostroph=false;
                }
                break;
            }
            else if(letter=='E'){
                if((outputWord.back()=='E' || outputWord.back()=='e') && apostroph){
                    outputWord+="'Eve";
                    apostroph=false;
                }
                else if(outputWord.back()!='E' && outputWord.back()!='e')
                    outputWord+="Eve";
                else{
                    if(outputWord.back()!='V' && outputWord.back()!='v')
                        outputWord+="Ve";
                }
                break;
            }
            else if(letter=='e'){
                if((outputWord.back()=='E' || outputWord.back()=='e') && apostroph){
                    outputWord+="'eve";
                    apostroph=false;
                }
                else if(outputWord.back()!='E' && outputWord.back()!='e')
                    outputWord+="eve";
                else{
                    if(outputWord.back()!='V' && outputWord.back()!='v')
                        outputWord+="ve";
                }
                break;
            }
            else if(letter=='Y'){
                if((outputWord.back()=='Y' || outputWord.back()=='y') && apostroph){
                    outputWord+="'Yt";
                    apostroph=false;
                }
                else if(outputWord.back()!='Y' && outputWord.back()!='y')
                    outputWord+="Yt";
                else{
                    if(outputWord.back()!='T' && outputWord.back()!='t')
                        outputWord+="T";
                }
                break;
            }
            else if(letter=='y'){
                if((outputWord.back()=='Y' || outputWord.back()=='Y') && apostroph){
                    outputWord+="'yt";
                    apostroph=false;
                }
                else if(outputWord.back()!='Y' && outputWord.back()!='y')
                    outputWord+="yt";
                else{
                    if(outputWord.back()!='T' && outputWord.back()!='t')
                        outputWord+="t";
                }
                break;
            }
            else if(letter==this->alphabetPLcapital[j]){
                if((outputWord.back()==alphabetKKcapital[j] || outputWord.back()==alphabetKKsmall[j]) && apostroph){
                    outputWord+='\'';
                    outputWord+=this->alphabetKKcapital[j];
                    apostroph=false;
                }
                else if(outputWord.back()!=alphabetKKcapital[j] && outputWord.back()!=alphabetKKsmall[j])
                    outputWord+=this->alphabetKKcapital[j];
                break;
            }
            else if(letter==this->alphabetPLsmall[j]){
                if((outputWord.back()==alphabetKKcapital[j] || outputWord.back()==alphabetKKsmall[j]) && apostroph){
                    outputWord+='\'';
                    outputWord+=this->alphabetKKsmall[j];
                    apostroph=false;
                }
                else if(outputWord.back()!=alphabetKKcapital[j] && outputWord.back()!=alphabetKKsmall[j])
                    outputWord+=this->alphabetKKsmall[j];
                break;
            }
        }
    }
    if(outputWord.back()=='Q')
        outputWord+='E';
    else if(outputWord.back()=='q')
        outputWord+='e';
    else if(outputWord.back()=='Y')
        outputWord+='I';
    else if(outputWord.back()=='y')
        outputWord+='i';
    return outputWord;
}

int main(){
    string word;
    KysKuoTranslator kkt;
    cout << "Podaj slowo, ktore chcesz przetlumaczyc:" << endl;
    while(true){
        cout << ">  ";
        cin >> word;
        string translation=kkt.translationPLtoKK(word);
        cout << ">> " << translation << endl << endl;
    }
    return 0;
}
