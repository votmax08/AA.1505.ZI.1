//
// ROT0 Vigenere Cipher
//

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
    bool bDecrypt = parser.optionExists("-d");

    if (!(is.is_open() && os.is_open() && ks.is_open()))
    {
        Usage(argv[0]);
        return 1;
    }

    vector<char> key((istreambuf_iterator<char>(ks)),
                     istreambuf_iterator<char>());

    size_t keyPos = 0;
    transform(istreambuf_iterator<char>(is), istreambuf_iterator<char>(), ostreambuf_iterator<char>(os), [key, &keyPos, &bDecrypt](const char &symbol)
    {
        static const size_t alphabet_len = (1 << 8 * sizeof(char));

        char result;
        if (!bDecrypt)
            result = (symbol + key[keyPos]) % alphabet_len;
        else
            result = (symbol - key[keyPos]) % alphabet_len;

        keyPos = (keyPos + 1) % key.size();

        return result;
    });

    return 0;
}
