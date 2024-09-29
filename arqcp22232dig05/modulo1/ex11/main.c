#include <stdio.h>

#include "palindrome.h"

void print(char *sentence) { printf("%s: %d\n", sentence, palindrome(sentence)); }

int main() {
    print("Never odd or even");
    print("A man a plan a canal Panama.");
    print("Gateman sees name, garageman sees nametag");
    print("");
    print(" ");
    print("1");
    print("a");
    print("   a ");
    print("   aba ");
    print("   aa ");
    print("   BB ");
    print("ababa");
    print("   ababa ");
}
