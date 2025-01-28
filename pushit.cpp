#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>

typedef int i;

i main(i args, char* argv[]) {
  std::string msgStore = argv[1];
  std::string command = "git commit -m \"" + msgStore + "\"";
  const char* commitCommand = command.c_str();
  i result = system("git add .");
  if(result  == 0) {
    i result2 = system(commitCommand);
    if (result2 == 0) {
      i result3 = system("git push origin main");
      if(result3 == 0) {
        std::cout << "repo Pushed" << std::endl;
      } else {
        std::cout << "Error happend in git push" << std::endl;
      }
    } else {
      std::cout << "Error happend in git commit" << std::endl;
    }
  } else {
    std::cout << "Error happend in git add" << std::endl;
  }
	return 0;
}