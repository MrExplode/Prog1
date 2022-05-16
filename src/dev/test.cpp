#include <iostream>

int main() {
    std::string data = "CheckRemoteDebuggerPresent";
    std::cout << "char d2[" << data.size() + 1 << "];" << std::endl;
    for (int i = 0; i < data.size(); i++) {
        std::cout << "d2[" << i << "] = 0x";
        unsigned char c = data[i];
        c ^= 0x12;
        c ^= 0xf7;
        c ^= 0x9e;
        c ^= 0x72;
        c ^= 0x8b;
        printf("%02x", c);
        std::cout << ";" << std::endl;
    }
    std::cout << "d2[" << data.size() << "] = 0x";
    printf("%02x", '\0');
    std::cout << ";" << std::endl;

    unsigned char d2[27];
		d2[0] = 0xc1;
		d2[1] = 0xea;
		d2[2] = 0xe7;
		d2[3] = 0xe1;
		d2[4] = 0xe9;
		d2[5] = 0xd0;
		d2[6] = 0xe7;
		d2[7] = 0xef;
		d2[8] = 0xed;
		d2[9] = 0xf6;
		d2[10] = 0xe7;
		d2[11] = 0xc6;
		d2[12] = 0xe7;
		d2[13] = 0xe0;
		d2[14] = 0xf7;
		d2[15] = 0xe5;
		d2[16] = 0xe5;
		d2[17] = 0xe7;
		d2[18] = 0xf0;
		d2[19] = 0xd2;
		d2[20] = 0xf0;
		d2[21] = 0xe7;
		d2[22] = 0xf1;
		d2[23] = 0xe7;
		d2[24] = 0xec;
		d2[25] = 0xf6;
		d2[26] = 0x00;
		for (unsigned int i = 0; i < sizeof(d2); i++)
		{
                unsigned char c = d2[i];
			if (c != '\0') {
			c ^= 0x12;
			c ^= 0xf7;
			c ^= 0x9e;
			c ^= 0x72;
			c ^= 0x8b;
			d2[i] = c;
            }
		}
        std::cout << d2 << std::endl;
}