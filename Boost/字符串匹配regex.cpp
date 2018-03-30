//
// Created by wenshao on 18-3-30.
//

#include <iostream>
#include <unordered_set>
#include <string>
#include <tuple>
#include <regex>
using namespace std;

//ununordered_set
int main11(){
    unordered_set<string> myset;
    myset.insert("abss");
    myset.insert("sffg");
    myset.insert("hello world");
    for(auto it:myset){
        cout<<it<<endl;
    }
    cout<<(myset.find("hello")!=myset.end())<<endl;
    return 0;
}
/*
1.      “.”： 匹配除"\n"之外的任何单个字符，若要匹配包括"\n"在内的任意字符，需使用诸如"[\s\S]"之类的模式；

	2.       “^”：匹配输入字符串的开始位置，不匹配任何字符，要匹配”^”字符本身，需使用”\^”；

	3.      “$”：匹配输入字符串结尾的位置，不匹配任何字符，要匹配”$”字符本身，需使用”\$”；

	4.      “*”： 零次或多次匹配前面的字符或子表达式，”*”等效于”{0,}”，如”\^*b”可以匹配”b”、”^b”、”^^b”、…；

	5.      “+”： 一次或多次匹配前面的字符或子表达式，等效于”{1,}”，如”a+b”可以匹配”ab”、”aab”、”aaab”、…；

	6.      “?”： 零次或一次匹配前面的字符或子表达式，等效于”{0,1}”，如”a[cd]?”可以匹配”a”、”ac”、”ad”； 当此字符紧随任何其他限定符”*”、”+”、”?”、”{n}”、”{n,}”、”{n,m}”之后时，匹配模式是"非贪心的"。"非贪心的"模式匹配搜索到的、尽可能短的字符串，而默认的"贪心的"模式匹配搜索到的、尽可能长的字符串。如，在字符串"oooo"中，"o+?"只匹配单个"o"，而"o+"匹配所有"o"；

	7.      “|”：将两个匹配条件进行逻辑"或"(Or)运算,如正则表达式”(him|her)”匹配"itbelongs to him"和"it belongs to her"，但是不能匹配"itbelongs to them."；

	8.      “\”： 将下一字符标记为特殊字符、文本、反向引用或八进制转义符，如，”n”匹配字符”n”,”\n”匹配换行符，序列”\\”匹配”\”,”\(“匹配”(“；

	9.      “\w”：匹配字母或数字或下划线，任意一个字母或数字或下划线，即A~Z，a~z,0~9,_中任意一个；

	10.  “\W”：匹配任意不是字母、数字、下划线的字符；

	11.  “\s”：匹配任意的空白符，包括空格、制表符、换页符等空白字符的其中任意一个，与”[ \f\n\r\t\v]”等效；

	12.  “\S”：匹配任意不是空白符的字符，与”[^\f\n\r\t\v]”等效；

	13.  “\d”：匹配数字，任意一个数字，0~9中的任意一个，等效于”[0-9]”；

	14.  “\D”：匹配任意非数字的字符，等效于”[^0-9]”；

	15.  “\b”： 匹配一个字边界，即字与空格间的位置，也就是单词和空格之间的位置，不匹配任何字符，如，"er\b"匹配"never"中的"er"，但不匹配"verb"中的"er";

	16.  “\B”： 非字边界匹配,"er\B"匹配"verb"中的"er"，但不匹配"never"中的"er"；

	17.  “\f”：匹配一个换页符，等价于”\x0c”和”\cL”；

	18.  “\n”：匹配一个换行符，等价于”\x0a”和”\cJ”；

	19.  “\r”：匹配一个回车符，等价于”\x0d”和”\cM”；

	20.  “\t”：匹配一个制表符，等价于”\x09”和”\cI”；

	21.  “\v”：匹配一个垂直制表符，等价于”\x0b”和”\cK”；

	22.  “\cx”：匹配”x”指示的控制字符,如，\cM匹配Control-M或回车符，”x”的值必须在”A-Z”或”a-z”之间,如果不是这样，则假定c就是"c"字符本身；

	23.  “{n}”：”n”是非负整数，正好匹配n次，如，"o{2}"与"Bob"中的"o"不匹配，但与"food"中的两个"o"匹配；

	24.  “{n,}”：”n”是非负整数,至少匹配n次,如，"o{2,}"不匹配"Bob"中的"o"，而匹配"foooood"中的所有”o”，"o{1,}"等效于"o+"，"o{0,}"等效于"o*"；

	25.  “{n,m}”：”n”和”m”是非负整数，其中n<=m，匹配至少n次，至多m次，如，"o{1,3}"匹配"fooooood"中的头三个o，'o{0,1}'等效于'o?'，注意,不能将空格插入逗号和数字之间；如”ba{1,3}”可以匹配”ba”或”baa”或”baaa”；

	26.  “x|y”：匹配”x”或”y”，如，”z|food”匹配"z"或"food"；”(z|f)ood”匹配"zood"或"food"；

	27.  “[xyz]”：字符集，匹配包含的任一字符，如，"[abc]"匹配"plain"中的"a";

	28.  “[^xyz]”：反向字符集，匹配未包含的任何字符，匹配除了”xyz”以外的任意字符，如，"[^abc]"匹配"plain"中的"p"；

	29.  “[a-z]”：字符范围，匹配指定范围内的任何字符，如，"[a-z]"匹配"a"到"z"范围内的任何小写字母；

	30.  “[^a-z]”：反向范围字符，匹配不在指定的范围内的任何字符，如，"[^a-z]"匹配任何不在"a"到"z"范围内的任何字符；

	31.  “( )”：将”(“和”)”之间的表达式定义为”组”group，并且将匹配这个表达式的字符保存到一个临时区域,一个正则表达式中最多可以保存9个，它们可以用”\1”到”\9”的符号来引用；

	32.  “(pattern)”：匹配pattern并捕获该匹配的子表达式，可以使用$0…$9属性从结果”匹配”集合中检索捕获的匹配；

	33.  “(?:pattern)”：匹配pattern但不捕获该匹配的子表达式，即它是一个非捕获匹配，不存储供以后使用的匹配，这对于用”or”字符” (|)”组合模式部件的情况很有用, 如，”industr(?:y|ies)”是比”industry|industries”更简略的表达式；

	34.  “(?=pattern)”： 非获取匹配，正向肯定预查，在任何匹配pattern的字符串开始处匹配查找字符串，该匹配不需要获取供以后使用。如，"Windows(?=95|98|NT|2000)"能匹配"Windows2000"中的"Windows"，但不能匹配"Windows3.1"中的"Windows"。预查不消耗字符，也就是说，在一个匹配发生后，在最后一次匹配之后立即开始下一次匹配的搜索，而不是从包含预查的字符之后开始；

	35.  “(?!pattern)”： 非获取匹配，正向否定预查，在任何不匹配pattern的字符串开始处匹配查找字符串，该匹配不需要获取供以后使用。如"Windows(?!95|98|NT|2000)"能匹配"Windows3.1"中的"Windows"，但不能匹配"Windows2000"中的"Windows"；

	要匹配某些特殊字符，需在此特殊字符前面加上”\”，如要匹配字符”^”、”$”、”()”、”[]”、”{}”、”.”、”?”、”+”、”*”、”|”，需使用” \^”、” \$”、” \ (“、”\)”、” \ [“、”\]”、” \{“、”\}”、” \.”、” \?”、” \+”、” \*”、” \|”。
 */


//regex_match：整个字符串是否匹配
int main22(){

    regex reg1("\\w+day");
    string s1 = "saturday";
    string s2 = "saturday and sunday";
    smatch r1;
    smatch r2;
    cout << boolalpha << regex_match(s1, r1, reg1) << endl;
    cout << boolalpha << regex_match(s2, r2, reg1) << endl;
    cout << "s1匹配结果：" << r1.str() << endl;
    cout << "s2匹配结果：" << r2.str() << endl;
    cout << endl;
    return 0;
}

//regex_match：只返回第一个匹配结果
int main33(){
    regex reg1("(\\w+)day");
    string s1 = "saturday";
    string s2 = "saturday and sunday";
    smatch rr1;
    smatch rr2;
    regex_search(s1, rr1, reg1);
    cout << "s1匹配结果：" << rr1.str() << endl;
    cout << boolalpha << regex_search(s2, rr2, reg1) << endl;
    cout << "s1匹配结果：" << rr2.str() << endl;
    cout << endl;
    return 0;
}

//iterator：返回多个匹配结果

//类似于指针，调用成员要用"->"

int main55(){
    regex reg1("(\\w+)day");
    string s1 = "saturday";
    string s2 = "saturday and sunday";
    cout << "iterator结果：" << endl;
    sregex_iterator it(s2.begin(), s2.end(), reg1);
    sregex_iterator end;
    for(; it != end; ++it)
    {
        cout << it->str() << endl;
        //cout << *it << endl; 错误
    }

    cout << "token_iterator结果：" << endl;
    sregex_token_iterator tit(s2.begin(), s2.end(), reg1);
    sregex_token_iterator tend;
    for(; tit != tend; ++tit)
    {
        cout << tit->str() << endl;
        cout << *tit << endl;
    }
    return 0;
}
//子表达式匹配
int main66(){
    regex reg2("(\\d{1,3}):(\\d{1,3}):(\\d{1,3}):(\\d{1,3})");
    string ip = "0:11:222:333";
    smatch m;
    regex_match(ip, m, reg2);
    cout << "输出：str()" << endl;
    cout << m.str() << endl;
    cout << m.str(1) << endl;
    cout << m.str(2) << endl;
    cout << m.str(3) << endl;
    cout << m.str(4) << endl;

    cout << "输出：[i]" << endl; //结果同上
    cout << m[0] << endl;
    cout << m[1] << endl;
    cout << m[2] << endl;
    cout << m[3] << endl;
    cout << m[4] << endl;
    return 0;
}

int main(){
    string ip2 = "0:11:222:333 4:55:66:7";
    regex reg2("(\\d{1,3}):(\\d{1,3}):(\\d{1,3}):(\\d{1,3})");
    sregex_iterator ip_it(ip2.begin(), ip2.end(), reg2);
    sregex_iterator ip_end;
    for(; ip_it != ip_end; ++ip_it) {
        cout << ip_it->str() << endl;
        cout << ip_it->str(1) << endl;
        cout << ip_it->str(2) << endl;
        cout << ip_it->str(3) << endl;
        cout << ip_it->str(4) << endl;
    }
    return 0;
}