#include "string_finder.h"
#include "cmd_parser.h"

int main(int argc, char *argv[]) {
  string_finder::CmdParser cmd_parser{argc, argv};
  string_finder::StringFinder string_finder;
  auto arguments = cmd_parser.getArguments();

  if(arguments->min_chars > 0)
    string_finder.set_min_chars(arguments->min_chars);
  if(!arguments->grep_chars.empty())
    string_finder.set_filter(arguments->grep_chars);

  for(auto &file: arguments->files) {
    auto stringsVector = string_finder.find_strings(file);
    for(auto &string: stringsVector) {
      std::cout << string << std::endl;
    }
  }
  return 0;
}
