#include <iostream>
#include <ctime>
#include <map>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unistd.h> //para getpass
#include <cstdio> //para remove
#include <algorithm>
#include <cctype>
class Contact {
	public:
		std::string zodiac (int day, int month) const;		          	int age(int day, int month, int year) const;
		std::string country(const std::string& prefix) const;
		std::string sherl(const std::string& alias, std::string name)const;

		Contact(std::string name,std::string alias, std::string number, std::string comment, std::string prefix, int day, int month, int year);


		
	private:
		std::string _name;
		std::string _alias;
		std::string _number;
		std::string _comment;
		std::string _prefix;
                int _day, _month, _year;

		static const std::map<std::string, std::string> countryCodes;
	        

};
const std::map<std::string, std::string> Contact::countryCodes = {

                	{"+1", "United States"},
			{"+49", "Germany"},
			{"+44", "United Kindom"},
			{"+33", "France"},
			{"+34", "Spain"},
			{"+55", "Brazil"},
			{"+57", "Colombia"},
			{"+91", "India"},
			{"+52", "Mexico"},
			{"+61", "Australia"},
			{"+39", "Italy"},
			{"+34", "Spain"},
			{"+81", "Japan"},
			{"+86", "China"},
			{"+7", "Russia"},
			{"+20", "Egypt"},
			{"+27", "South Africa"},
			{"+31", "Netherlands"},
			{"+41", "Switzerland"}

};

Contact::Contact(std::string name, std::string alias, std::string number, std::string comment, std::string prefix, int day, int month, int year) : _name(name), _alias(alias), _number(number), _comment(comment), _prefix(prefix), _day(day), _month(month), _year(year) {}

//-
std::string Contact::zodiac(int day, int month) const {
	if ((month == 1 && day >= 20) || (month == 2 && day <= 18 )) {

	return "Aquarius";

	} else if ((month == 2 && day >= 19)|| (month == 3 && day <= 20)){

	return "Pisces";

	} else if ((month == 3 && day >= 21) || (month == 4 && day <= 19)) {
	
	return "Aries";

	} else if ((month == 4 && day >= 20)||(month == 5 && day <= 19)) {
	
	return "Taurus";

	} else if ((month == 5 && day >= 21 )||(month == 6 && day <= 20)) {

	return "Gemini";

	}else if ((month == 6 && day >= 21)||(month == 7 && day <= 22)) {

	return "Cancer";

	}else if ((month ==7 && day >= 23)||(month == 8 && day <= 22)) {
        return "Leo";

	}else if ((month == 8 && day >= 23)||(month == 9 && day <= 22 )){

	return "Virgo";

	}else if ((month == 9 && day >= 23)||(month ==10 && day <= 22)){

	return "libra";

	}else if ((month == 10 && day >= 23)||(month == 11 && day <= 21)){

	return " Scorpio";

	}else if ((month == 11 && day >= 22)||(month == 12 && day <= 21)) {

	return "Sagitarius";

	}else if ((month == 12 && day >= 22)||(month == 1 && day <= 19)) {

	return "Capricorn";
	}

	return "Invalid date";
}
//-
int Contact::age(int day, int month, int year) const {
	time_t t = time(0);
	tm* now = localtime(&t);

	int currentYear = now->tm_year + 1900;
	int currentMonth = now->tm_mon + 1;
	int currentDay = now->tm_mday;

	//calcular edad
	int agee = currentYear - year;
        if (month > currentMonth || (month == currentMonth && day > currentDay)) {
	agee--;
	}
	return agee;
}
//-
std::string Contact::country(const std::string& prefix) const {
	std::string cleanPrefix = prefix;
	cleanPrefix.erase(remove(cleanPrefix.begin(), cleanPrefix.end(),' '), cleanPrefix.end());

	if (prefix[0] != '+'){
	return "Unknown";
	}
	auto it = countryCodes.find(cleanPrefix);
	if (it != countryCodes.end()) {
	return it->second;
	}
	return "Unknown";
	std::cout << "debug Prefix: " << prefix <<std::endl;

}
//-
std::string Contact::sherl(const std::string& alias, std::string name) const {
	const std::string filename = "nicknames.txt";


	std::ifstream inFile(filename);
	bool fileExists = inFile.good();
	inFile.close();

	if (!fileExists){
		std::ofstream createFile(filename);
		if (!createFile){
			std::cerr << "Error creando el archivo " << filename << std::endl;
			return "Error";
		}
		createFile.close();
	}
	inFile.open(filename);
	std::string line;
	bool nameExists = false;


	if (!inFile) {
	std::cerr << "Error opening file: " << filename << std::endl;
	return "Error";
	}

	while (std::getline(inFile, line)) {

	if (line.find(" Nickname: " + alias) != std::string::npos) {
		nameExists = true;
		break;

	}
	}
	inFile.close(); //cerrar archivo de lectura 
	if (nameExists) {
	return "Nickname already exists: " + alias;
	}
	//si no existe se agraga el archivo 
	std::ofstream outFile(filename, std::ios::app);
	if (!outFile) {
	std::cerr << "Error opening file: "<< filename << std::endl;
	return "Error";
	}

	outFile <<"Name: "<< name << " Nickname: "<< alias << std::endl;
	outFile.close();

	return "Nickname added: "+ alias; 
	
}
std::string saveToFile(const Contact& contact, int day, int month, int year,std::string number,std::string comment,std::string name,const std::string& alias, const std::string& prefix ){

	const std::string filename = "xontacts.txt";

	std::ifstream inFile(filename);
	bool fileExists = inFile.good();
	inFile.close();
	//si no existe lo crea
	if (!fileExists) {
		std::ofstream createFile(filename);
	if (!createFile){
		std::cerr << "Error creando el archivo: "<< filename << std::endl;
		return "Error";
	}
	createFile.close();
	}
	//verifica si el nombre ya existe en el archivo 
	inFile.open(filename);
	std::string line;
	bool nameExists = false;

	if (!inFile) {
	std::cerr << "Error opening file: " << filename<< std::endl;
	return "Error";

	}
	while (std::getline(inFile, line)) {
	if (line.find("Name: " + name) != std::string::npos) {
		nameExists = true;
		break;
	}
	}

	inFile.close();
	if (nameExists){
	return "Name already exists: " + name;
	}

	
	std::ofstream outFile(filename, std::ios::app);

	if (!outFile) {
		std::cerr << "Error opening file: " << filename << std::endl;
		return "Error";
	}

        outFile << "-----------" << std::endl;
	outFile << "Name: " << name << std::endl;
	outFile << "Country Code: "<< prefix << std::endl;
	outFile << "Phone Number: " << number << std::endl;
	outFile << "Age: "<< contact.age(day, month, year) << " years old\n";
	outFile << "Birthday: "<< day << "." << month <<"."<<year <<"\n";
	outFile << "Nickname: "<< alias << std::endl;
	outFile << "Zodiac Sign: "<< contact.zodiac(day, month) << "\n";
	outFile << "Country: "<< contact.country(prefix) << "\n";
	outFile << "Comment: "<< comment << std::endl;
	outFile << "-----------" << std::endl;

	outFile.close();
	

	return "Data saved successfully to: " + filename;
	

}
bool veriNumber(const std::string& number) {
size_t length = number.length();
if (length >= 5 && length <= 11){
	std::cout << "The number is Valid. \n";
	return true;
}else {
	std::cout << "invalid number. \n";
	return false;
}
}
bool isNumberValid(const std::string& number) {
for (char c : number){
if (!std::isdigit(c)){
return false;
}
}
return true;
}
std::string toLowerCase (const std::string& str){
	std::string result = str;
	std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return std::tolower(c); });
			return result;
}

//-
void encryptFile(const std::string& filename, const std::string& password){
	
	std::string tempFile = filename + "tmp";
	std::string command = "openssl enc -aes-256-cbc -salt -in \"" + filename + "\" -out \"" + tempFile + "\" -pass pass:\"" + password+ "\" -pbkdf2";

	int result = system(command.c_str());
	if (result != 0){
	std::cerr << "Error encrypting File."<<std::endl;
	return;
	} 
	if(std::remove(filename.c_str()) != 0) {
	std::cerr << "Error deleting original file: "<< filename << std::endl;
	return;
	}
	if (std::rename(tempFile.c_str(), filename.c_str()) != 0) {
		std::cerr << "Error renaming encrypted file to original filename."<< std::endl;
	return;
	}
	std::cout << "File encrypted successfully and original file replaced." << std::endl;
}

void decryptFile(const std::string& filename, const std::string& password){
	std::string tempFile = filename + "tmp";
	std::string command = "openssl enc -d -aes-256-cbc -pbkdf2 -in \"" + filename + "\" -out \"" + tempFile + "\" -pass pass:\"" + password + "\"";
	int result = system(command.c_str());
	if (result != 0) {
	std::cerr << "Error decrypting file." << std::endl;
	return;
	}
	if (std::remove(filename.c_str())!=0){
		std::cerr << "Error deliting encrypted file: " << filename << std::endl;
		return;

	}
	if (std::rename (tempFile.c_str(),filename.c_str()) != 0) {
        std::cerr << "Error renaming decrypted file to original filename." << std::endl;
	return;

	} 
	std::cout << "File decrypted successfully and original file replaced."<<std::endl;
}
int main () {
	std::string name, alias, comment, prefix, number;
	int day, month, year;
	std::string password;
	std::string filename = "xontacts.txt";
         
	std::cout << "looking for your encrypted file, if i can't find it i'll create it."<<std::endl;
	std::ifstream inFile(filename);
	bool fileExists = inFile.good();
	inFile.close();

	if (fileExists){
		password = getpass("Enter password to decrypt file: ");
	decryptFile(filename, password);
	} else {
	 password = getpass("Enter a new Pin to create and encrypt the file: ");
}

	std::cout << "Hey Buddy, Let's Add Someone" <<std::endl;
	std::cout << "Add Name: " <<std::endl;
	std::getline(std::cin, name);
	name = toLowerCase(name);
	std::cout << "Add Nickname: " <<std::endl;
	std::getline(std::cin, alias);
	alias = toLowerCase(alias);
	std::cout <<"Add Country Code: " <<std::endl;
	std::getline(std::cin, prefix);

	bool validNumber = false;
	while(!validNumber){
	std::cout << "Add Phone Number: " <<std::endl;
	std::getline(std::cin, number); 
	if (!veriNumber(number)){
		std::cout << "El numero no es valido, no se guardaran los datos. \n";
		return 1;
	}
	if (isNumberValid(number)){
validNumber = true;
	}else {
		std::cout << "El Numero no es valido, porfavoringresa solo numeros"<< std::endl;
	}
	}
	std::cout <<"Add Birthday dd mm yyyy: " <<std::endl;
	std::cin >> day >> month >> year;
	std::cin.ignore();
	std::cout <<"Add Comment: " <<std::endl;
	std::getline (std::cin, comment);

	Contact contact(name, alias, number, "", prefix, day, month, year);

        std::cout << "Name: " << name <<"\n";
	std::cout << "Born: " << day <<"."<< month << "." << year <<"\n";
	std::cout << "Nickname: " << alias <<"\n";
	std::cout << "Number: " << number <<"\n";
	std::cout << "Age: " << contact.age(day, month, year) << " years old\n";
	std::cout <<"Zodiac sign: " << contact.zodiac(day, month) << "\n"; 
	std::cout << "Country: " << contact.country(prefix) << "\n"; 
	std::cout << "Comment: " << comment << std::endl;
        std::string resultNickname = contact.sherl(alias, name); 
	std::string resultContact = saveToFile(contact, day, month, year, number, comment, name, alias, prefix );
	std::cout << resultNickname << "\n";
	std::cout << resultContact << "\n";

	
	encryptFile(filename, password);

 	
	return 0;
}
