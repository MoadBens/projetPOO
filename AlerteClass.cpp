#include "AlerteClass.h"

AlerteClass::AlerteClass() {
}
AlerteClass::AlerteClass(std::string message, std::string desti) {
	message_ = message;
	destinateur_ = desti;
}
std::string AlerteClass::get_Message() {
	return message_;
}
void AlerteClass::set_Message(std::string message){
	message_ = message;
}
std::string  AlerteClass::get_desti() {
	return destinateur_;
}
void AlerteClass::set_desti(std::string desti) {
	destinateur_ = desti;
}