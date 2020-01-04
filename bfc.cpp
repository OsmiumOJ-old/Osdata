// BrainF*** Compiler version 1.0.0 by HJGranger.
#include <cstdio>
#include <cstdlib>
#include <cstring>

inline void help(void) {
	std::printf(
		"Usage: bfc [InputFileName] [OutputFileName] [MemoryLimitinByte] [Options]\n"
		"	   or\n"
		"	   bfc [Option]\n"
		"What's [Options]?\n"
		"	We use g++ to compile your BF code. BFC will only change your BF code to C++\n"
		"	lang code. So the options is the options of g++. For example, \n"
		"	bfc a.bf a 1024 -std=c++17\n"
		"	will compile your C++ code with option -std=c++17 to the compiler g++.\n"
		"What's [Option] then?\n"
		"	Sometimes you may want to know, 'Which version does my BFC use? Well, you\n"
		"	might want to use bfc --version or bfc -v to get version number. However,\n"
		"	you might think, 'How can BFC know that this is an option only for BFC but\n"
		"	not g++? Well, BFC is clever enough to know you want to get the version\n"
		"	number but not to compile the file '--version' or to get the version\n"
		"	number of g++. You only have to enter 'bfc -v' to get it.\n"
		"[Option] list:\n"
		"	-v or --version:\n"
		"		 get the version number.\n"
		"	-h or --help:\n"
		"		 get this help.\n"
	);
	return;
}

inline void version(void) {
	std::printf(
		"BrainF*** language Compiler version 1.0.0"
	);
	return;
}

inline bool equal(char* const str1, char* const str2) {
	return std::strcmp(str1, str2) == 0;
}

char str[] = "";

signed main(signed argc, char** argv) {
	if (equal(argv[1], "--version") || equal(argv[1], "-v")) {
		version();
		return 0;
	}
	if (equal(argv[1], "--help") || equal(argv[1], "-h")) {
		help();
		return 0;
	}
	FILE *inp = std::fopen(argv[1], "r");
	
	// std::freopen("tmp.c", "w", stdout);
	// std::fclose(stdout);
	
	FILE *out = std::fopen("tmp.cpp", "w");
	
	char ch;
	
	std::fprintf(
		out,
		"#include<stdio.h>\n"
		"#define a while(*p){\n"
		"#define b }\n"
		"#define c ++p;p==r?p=l:0;\n"
		"#define d p==l?p=r:--p;\n"
		"#define e ++(*p);\n"
		"#define f --(*p);\n"
		"#define g *p=getchar();\n"
		"#define h putchar(*p);\n"
		"main(){int*l=new int[%s],*r=l+%s,*p=l;\n",
		argv[3],
		argv[3]
	);
	
	while (~fscanf(inp, " %c", &ch)) {
		switch (ch) {
			case '[':
				std::fprintf(out, "a ");
				break;
			case ']':
				std::fprintf(out, "b ");
				break;
			case '>':
				std::fprintf(out, "c ");
				break;
			case '<':
				std::fprintf(out, "d ");
				break;
			case '+':
				std::fprintf(out, "e ");
				break;
			case '-':
				std::fprintf(out, "f ");
				break;
			case ',':
				std::fprintf(out, "g ");
				break;
			case '.':
				std::fprintf(out, "h ");
				break;
		}
	}
	
	std::fprintf(out, "return 0;}");
	std::fclose(inp);
	std::fclose(out);
	
	std::sprintf(str, "g++ tmp.cpp -o %s", argv[2]);
	
	for (int i = 4; i < argc; ++i) {
		std::sprintf(str, "%s %s", str, argv[i]);
	}
	
	std::system(str);
	
	return 0;
}