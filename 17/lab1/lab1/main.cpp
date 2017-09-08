//
// ROT0 Vigenere Cipher
//

#include <cstdint>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//
// From https://stackoverflow.com/questions/865668/how-to-parse-command-line-arguments-in-c
//
class InputParser
{
public:
    InputParser(int argc, const char *argv[])
    {
        for (int i = 1; i < argc; i++)
        {
            tokens.push_back(string(argv[i]));
        }
    }

    string getOption(const string &option) const
    {
        vector<string>::const_iterator it;
        it = find(tokens.begin(), tokens.end(), option);
        if (it != tokens.end() && ++it != tokens.end())
        {
            return *it;
        }

        return "";
    }

    bool optionExists(const string &option) const
    {
        return find(tokens.begin(), tokens.end(), option) != tokens.end();
    }

private:
    std::vector<string> tokens;
};

void Usage(const char *pName)
{
    cout << "Usage: " << pName << " -k <keyfile> -i <infile> -o <outfile> [-d]" << endl;
}

int main(int argc, const char *argv[])
{
    InputParser parser(argc, argv);

    ifstream ks(parser.getOption("-k"), ifstream::binary);
    ifstream is(parser.getOption("-i"), ifstream::binary);
    ofstream os(parser.getOption("-o"));
    bool bDecode = parser.optionExists("-d");

    if (!(is.is_open() && os.is_open() && ks.is_open()))
    {
        Usage(argv[0]);
        return 1;
    }

    std::vector<uint8_t> key((istreambuf_iterator<char>(ks)),
                             istreambuf_iterator<char>());

    size_t pos = 0;
    istreambuf_iterator<char> ii(is), ie;
    ostreambuf_iterator<char> oi(os);
    while(ii != ie)
    {
        uint8_t byte = *(ii++);

        if (!bDecode)
            byte = (byte + key[pos % 3]) % 256;
        else
            byte = (byte - key[pos % 3]) % 256;

        oi = (char)byte;
        oi++;

        pos++;
    }

    return 0;
}
