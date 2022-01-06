#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <time.h>

using namespace std;
vector<float> memory;
vector<float> stck;
vector<string> links_names;
vector<int> links;
bool showMemory = false;

void print (string str)
{
	cout << str;
}

void set (string type, string new_mean, char sign)
{
	if (type.size() > 3)
	{
		if (type[0] == 'm' && type[1] == 'e' && type[2] == 'm')
		{
			string place;
			float meaning;
			if (type[3] == '$')
			{
				string typeNAME;
				string place22;
				bool find = false;
				for (int i = 4; i < type.size(); i++)
					typeNAME = typeNAME + type[i];
				for (int i = 0; i < links_names.size(); i++)
				{
					if (typeNAME == links_names[i])
					{
						find = true;
						place22 = to_string(links[i]);
					}
				}
				if (!find)
				{
					for (int i = 4; i < type.size(); i++)
					{
						place22 = place22 + type[i];
					}
				}
				place = to_string(memory[stoi(place22)]);
			}
			else
			{
				for (int i = 3; i < type.size(); i++)
				{
					place = place + type[i];
				}
			}
			while (memory.size() < stoi(place) + 1)
				memory.push_back(0);
			if (new_mean.size() > 3)
			{
				string place2;
				if (new_mean[0] == 'm' && new_mean[1] == 'e' && new_mean[2] == 'm')
				{
					if (new_mean[3] == '$')
					{
						string place22;
						string typeNAME;
						bool find = false;
						for (int i = 4; i < new_mean.size(); i++)
							typeNAME = typeNAME + new_mean[i];
						for (int i = 0; i < links_names.size(); i++)
						{
							if (typeNAME == links_names[i])
							{
								find = true;
								place22 = to_string(links[i]);
							}
						}
						if (!find)
						{
							for (int i = 4; i < new_mean.size(); i++)
							{
								place22 = place22 + new_mean[i];
							}
						}
						place2 = to_string(memory[stoi(place22)]);
					}
					else
					{
						for (int i = 3; i < new_mean.size(); i++)
						{
							place2 = place2 + new_mean[i];
						}
					}
					meaning = memory[stoi(place2)];
				}
				else if (new_mean == "true")
					meaning = 1;
				else if (new_mean == "false")
					meaning = 0;
				else
					meaning = stof(new_mean);
			}
			else
			{
				int place22;
				bool find = false;
				for (int i = 0; i < links_names.size(); i++)
				{
					if (new_mean == links_names[i])
					{
						find = true;
						place22 = links[i];
					}
				}
				if (!find)
				{
					if (new_mean[0] != '0' && new_mean[0] != '1' && new_mean[0] != '2' && new_mean[0] != '3' && new_mean[0] != '4' && new_mean[0] != '5' && new_mean[0] != '6' && new_mean[0] != '7' && new_mean[0] != '8' && new_mean[0] != '9')
						cout << "ERROR: no variable \'" << new_mean << "\'" << endl;
					else
						meaning = stof(new_mean);
				}
				else
					meaning = memory[place22];
			}
			if (sign == '=')
				memory[stoi(place)] = meaning;
			if (sign == '+')
				memory[stoi(place)] += meaning;
			if (sign == '-')
				memory[stoi(place)] -= meaning;
			if (sign == '*')
				memory[stoi(place)] *= meaning;
			if (sign == '/')
				memory[stoi(place)] /= meaning;
			if (sign == '%')
				memory[stoi(place)] = (int)memory[stoi(place)] % (int)meaning;
		}
	}
	else
	{
		bool find = false;
		int place, place2;
		for (int i = 0; i < links_names.size() && !find; i++)
		{
			if (type == links_names[i])
			{
				find = true;
				place = links[i];
			}
		}
		if (!find)
		{
			memory.push_back(0);
			links.push_back(memory.size() - 1);
			links_names.push_back(type);
			place = memory.size() - 1;
		}
		find = false;
		if (new_mean.size() > 3)
		{
			string place22 = "0";
			if (new_mean[0] == 'm' && new_mean[1] == 'e' && new_mean[2] == 'm')
			{
				if (new_mean[3] == '$')
				{
					string place222;
					string typeNAME;
					bool find = false;
					for (int i = 4; i < new_mean.size(); i++)
						typeNAME = typeNAME + new_mean[i];
					for (int i = 0; i < links_names.size(); i++)
					{
						if (typeNAME == links_names[i])
						{
							find = true;
							place222 = to_string(links[i]);
						}
					}
					if (!find)
					{
						for (int i = 4; i < new_mean.size(); i++)
						{
							place222 = place222 + new_mean[i];
						}
					}
					place22 = to_string(memory[stoi(place222)]);	
				}
				else
				{
					for (int i = 3; i < new_mean.size(); i++)
					{
						place22 = place22 + new_mean[i];
					}
				}
				new_mean = to_string(memory[stoi(place22)]);
			}
			else if (new_mean == "true")
				new_mean = "1";
			else if (new_mean == "false")
				new_mean = "0";
		}
		else
		{
			for (int i = 0; i < links_names.size(); i++)
			{
				if (new_mean == links_names[i])
				{
					find = true;
					place2 = links[i];
				}
			}
		}
		float meaning;
		if (!find)
		{
			if (new_mean[0] != '0' && new_mean[0] != '1' && new_mean[0] != '2' && new_mean[0] != '3' && new_mean[0] != '4' && new_mean[0] != '5' && new_mean[0] != '6' && new_mean[0] != '7' && new_mean[0] != '8' && new_mean[0] != '9')
				cout << "ERROR: no variable \'" << new_mean << "\'" << endl;
			else
				meaning = stof(new_mean);
		}
		else
			meaning = memory[place2];

		if (sign == '=')
			memory[place] = meaning;
		else if (sign == '+')
			memory[place] += meaning;
		else if (sign == '-')
			memory[place] -= meaning;
		else if (sign == '*')
			memory[place] *= meaning;
		else if (sign == '/')
			memory[place] /= meaning;
		else if (sign == '%')
			memory[place] = (int)memory[place] % (int)meaning;
	}
}

float take (string type)
{
	float ret = 0;
	if (type.size() > 3)
	{
		if (type[0] == 'm' && type[1] == 'e' && type[2] == 'm')
		{
			string place;
			if (type[3] == '$')
			{
				string place2;
				string typeNAME;
				bool find = false;
				for (int i = 4; i < type.size(); i++)
					typeNAME = typeNAME + type[i];
				for (int i = 0; i < links_names.size(); i++)
				{
					if (typeNAME == links_names[i])
					{
						find = true;
						place2 = to_string(links[i]);
					}
				}
				if (!find)
				{
					for (int i = 4; i < type.size(); i++)
					{
						place2 = place2 + type[i];
					}
				}
				place = to_string(memory[stoi(place2)]);
			}
			else
			{
				for (int i = 3; i < type.size(); i++)
				{
					place = place + type[i];
				}
			}
			if (stoi(place) < memory.size())
				ret = memory[stoi(place)];
			else 
				ret = 0;
		}
		else if (type == "true")
			ret = 1;
		else if (type == "false")
			ret = 0;
		else
		{
			if (type[0] != '0' && type[0] != '1' && type[0] != '2' &&  type[0] != '3' && type[0] != '4' && type[0] != '5' && type[0] != '6' && type[0] != '7' && type[0] != '8' && type[0] != '9')
				ret = 0;
			else
				ret = stof(type);
		}
	}
	else
	{
		bool find = false;
		int place;
		for (int i = 0; i < links_names.size(); i++)
		{
			if (type == links_names[i])
			{
				find = true;
				place = links[i];
			}
		}
		if (!find)
		{
			if (type[0] != '0' && type[0] != '1' && type[0] != '2' &&  type[0] != '3' && type[0] != '4' && type[0] != '5' && type[0] != '6' && type[0] != '7' && type[0] != '8' && type[0] != '9')
				ret = 0;
			else
				ret = stof(type);
		}
		else
			ret = memory[place];
	}
	return ret;
}

int main()
{
	srand(time(NULL));
	string ASCII = "\n?????????????????????????????????\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ ";
	string path;
	getline(cin, path);
	ifstream file(path);
	string line;
	int lastPlace;
	vector<string> lines;
	vector<string> words;
	// checking is file open?
	if (file.is_open())
		cout << "file is open" << endl;
	// puting lines of file in vector
	while (getline(file, line))
	{
		lines.push_back(line);
	}
	// generate words from line
	for (auto l : lines)
	{
		if (l[0] != '/' || l[1] != '/')
		{
			string word;
			for (int i = 0; i < l.size(); i++)
			{
				if (l[i] != ' ' && l[i] != '(' && l[i] != ')' && l[i] != '\"' && l[i] != '#' && l[i] != '\t')
					word = word + l[i];
				else
				{
					if (word != "")
						words.push_back(word);
					if (l[i] == '(' || l[i] == ')' || l[i] == '#' || l[i] == '\"')
						words.push_back(string(1, l[i]));
					word = "";
				}
				if (i == l.size() - 1 && word != "")
					words.push_back(word);
			}
		}
	}
	// reading code loop
	for (int W = 0; W < words.size(); W++)
	{
		if (words[W] == "#") 
		{
			W++;
			if (words[W] == "print")
			{
				W++;
				if (words[W] == "(")
				{
					W++;
					string str;
					while (words[W] != ")")
					{
						if (words[W] == "\"")
						{
							W++;
							while (words[W] != "\"")
							{
								if (words[W] != "\\0" && words[W] != "\\n")
									str = str + words[W];
								else if (words[W] == "\\0")
									str = str + " ";
								else if (words[W] == "\\n")
									str = str + "\n";
								W++;
								if (W == words.size())
								{
									cout << "ERROR: missing \'\"\'" << endl;
									break;
								}
							}
						}
						else if (words[W][0] == '@')
						{
							string name;
							for (int i = 1; i < words[W].size(); i++)
							{
								name = name + words[W][i];
							}
							cout << ASCII[(int)take(name)];
						}
						else 
						{
							str = str + to_string((int)take(words[W])) + ".";
							int after_point = (int)(take(words[W]) * 1000) - (int)take(words[W]) * 1000;
							if (after_point != 0)
							{
								while (after_point % 10 == 0)
									after_point /= 10;
							}	
							str = str + to_string(after_point);
						}
						if (W == words.size())
						{
							cout << "ERROR: missing \')\'" << endl;
							break;
						}
						W++;
					}
					print(str);
				}
				else
				{
					cout << "ERROR: missing \'(\'" << endl;
					W = words.size();
				}
			}
			else if (words[W] == "file.open.read")
			{
				W++;
				if (words[W] == "(")
				{
					W++;
					if (words[W] == "\"")
					{
						int startPlace;
						W++;
						ifstream FILE(words[W]);
						if (!FILE.is_open())
						{
							cout << "ERROR: no such file or directory \'" << words[W] << "\'" << endl;
							W = words.size();
						}
						W++;
						if (words[W] == "\"")
						{
							W++;
							startPlace = take(words[W]) + 1;
							vector<string> lines;
							vector<char> chars;
							string line;
							while(getline(FILE, line))
							{
								lines.push_back(line);
							}
							for (auto el : lines)
							{
								for (int i = 0; i < el.size(); i++)
								{
									chars.push_back(el[i]);
								}
								chars.push_back('\n');
							}
							while (memory.size() < chars.size() + startPlace)
							{
								memory.push_back(0);
							}
							int push_num;
							memory[startPlace - 1] = chars.size();
							for (int i = 0; i < chars.size(); i++)
							{
								for (int j = 0; j < ASCII.size(); j++)
								{
									if (chars[i] == ASCII[j])
									{
										push_num = j;
										break;
									}
									else if (chars[i] == '!')
									{
										push_num = 0;
										break;
									}
								}
								memory[startPlace + i] = push_num;
							}
							W++;
							if (words[W] != ")")
							{
								cout << "ERROR: missing \')\'" << endl;
							}
						}
						else
						{
							cout << "ERROR: missing \'\"\'" << endl;
							W = words.size();
						}
						FILE.close();
					}
					else
					{
						cout << "ERROR: missing \'\"\'" << endl;
						W = words.size();
					}
				}
				else 
				{
					cout << "ERROR: missing \'(\'" << endl;
					W = words.size();
				}
			}
			else if (words[W] == "file.open.write")
			{
				W++;
				if (words[W] == "(")
				{
					W++;
					if (words[W] == "\"")
					{
						W++;
						ofstream FILE(words[W]);
						if (!FILE.is_open())
						{
							cout << "ERROR: no such file or directory \'" << words[W] << "\'" << endl;
							W = words.size();
						}
						W++;
						if (words[W] == "\"")
						{
							W++;
							if (words[W] == ")")
							{
								W++;
								while (words[W] != "file.close")
								{
									if (words[W] == "<<") 
									{
										W++;
										if (words[W] == "(")
										{
											W++;
											int start, end, mov;
											start = stoi(words[W]);
											W++;
											mov = stoi(words[W]);
											W++;
											end = stoi(words[W]);
											W++;
											if (words[W] != ")")
											{
												cout << "ERROR: missing \')\'" << endl;
												W = words.size();
											}
											if (words[W + 1] == "@")
											{
												W++;
												for (int i = start; i <= end; i += mov)
												{
													FILE << ASCII[(int)memory[i]];
												}

											}
											else
											{
												for (int i = start; i <= end; i += mov)
												{
													FILE << memory[i];
												}
											}
										}
										else
										{
											if (words[W][0] == '@')
											{
												string name;
												for (int i = 1; i < words[W].size(); i++)
												{
													name = name + words[W][i];
												}
												FILE << ASCII[(int)take(name)];
											}
											else
												FILE << take(words[W]);
										}
									}
									W++;
								}
							}
							else
							{
								cout << "ERROR: missing \')\'" << endl;
								W = words.size();
							}
						}
						else
						{
							cout << "ERROR: missing \'\"\'" << endl;
							W = words.size();
						}
						FILE.close();
					}
					else
					{
						cout << "ERROR: missing \'\"\'" << endl;
						W = words.size();
					}
				}
				else
				{
					cout << "ERROR: missing \'(\'" << endl;
					W = words.size();
				}
			}
			else if (words[W] == "sys.cls")
				cout << "\033c";
			else if (words[W] == "rule.showMemory")
				showMemory = true;
			else if (words[W] == "rand")
			{
				W++;
				if (words[W] == "(")
				{
					int point, mean;
					W++;
					W++;
					point = take(words[W]);
					set(words[W - 1], to_string(rand() % point), '=');
					W++;
					if (words[W] != ")")
					{
						cout << "ERROR: missing \')\'" << endl;
						W = words.size();
					}
				}
				else 
				{
					cout << "ERROR: missing \'(\'" << endl;
					W = words.size();
				}
			}
			else if (words[W] == "int")
			{
				W++;
				if (words[W] == "(")
				{
					W++;
					int mean = (int)take(words[W]);
					W++;
					set(words[W], to_string(mean), '=');
					W++;
					if (words[W] != ")")
					{
						cout << "ERROR: missing \')\'" << endl;
						W = words.size();
					}
				}
				else
				{
					cout << "ERROR: missing \'(\'" << endl;
					W = words.size();
				}
			}
			else if (words[W] == "stack.push")
			{
				W++;
				if (words[W] == "(")
				{
					W++;
					stck.push_back(take(words[W]));
					W++;
					if (words[W] != ")")
					{
						cout << "ERROR: missing \')\'" << endl;
						W = words.size();
					}
				}
				else 
				{
					cout << "ERROR: missing \'(\'" << endl;
					W = words.size();
				}
			}
			else if (words[W] == "stack.pop")
			{
				W++;
				if (words[W] == "(")
				{
					W++;
					set(words[W], to_string(stck[stck.size() - 1]), '=');
					stck.pop_back();
					W++;
					if (words[W] != ")")
					{
						cout << "ERROR: missing \')\'" << endl;
						W = words.size();
					}
				}
				else 
				{
					cout << "ERROR: missing \'(\'" << endl;
					W = words.size();
				}
			}
			else
			{
				string ID = words[W];
				lastPlace = W;
				bool flag = true;
				W--;
				while (words[W] != ID + ":" && W >= 0)
				{
					W--;
					if (W < 0)
						flag = false;
				}
				if (!flag)
				{
					W = lastPlace;
					W++;
				}
				while (words[W] != ID + ":" && !flag)
					W++;
			}
		}
		else if (words[W] == "=")
		{
			set(words[W - 1], words[W + 1], '=');
			W++;
		}
		else if (words[W] == "+=")
		{
			set(words[W - 1], words[W + 1], '+');
			W++;
		}
		else if (words[W] == "-=")
		{
			set(words[W - 1], words[W + 1], '-');
			W++;
		}
		else if (words[W] == "*=")
		{
			set(words[W - 1], words[W + 1], '*');
			W++;
		}
		else if (words[W] == "/=")
		{
			set(words[W - 1], words[W + 1], '/');
			W++;
		}
		else if (words[W] == "%=")
		{
			set(words[W - 1], words[W + 1], '%');
			W++;
		}
		else if (words[W] == "<<" && words[W + 1] == "user")
		{
			char input;
			cin >> input;
			int num;
			for (int i = 0; i < ASCII.size(); i++)
			{
				if (input == ASCII[i])
				{
					num = i;
					break;
				}
			}
			set(words[W - 1], to_string(num), '=');
			W++;
		}

		else if (words[W] == "?")
		{
			float mean1, mean2;
			bool go = false;
			mean1 = take(words[W + 1]);
			mean2 = take(words[W + 3]);
			if (words[W + 2] == "==")
			{
				if (mean1 == mean2)
					go = true;
			}
			if (words[W + 2] == ">")
			{
				if (mean1 > mean2)
					go = true;
			}
			if (words[W + 2] == "<")
			{
				if (mean1 < mean2)
					go = true;
			}
			if (words[W + 2] == ">=")
			{
				if (mean1 >= mean2)
					go = true;
			}
			if (words[W + 2] == "<=")
			{
				if (mean1 <= mean2)
					go = true;
			}
			if (words[W + 2] == "!=")
			{
				if (mean1 != mean2)
					go = true;
			}
			W += 4;
			if (words[W] != "{")
				cout << "ERROR: missing \'{\'" << endl;
			if (!go)
			{
				int brackets = 1;
				while(brackets != 0)
				{
					W++;
					if (words[W] == "}")
						brackets--;
					else if (words[W] == "{")
						brackets++;
					if (W == words.size() && brackets != 0)
					{
						cout << "ERROR: missing \'}\'" << brackets << ", " << W << endl;
						break;
					}
				}
			}
		}
		else if (words[W] == "return")
			W = lastPlace;
	}
	cout << endl;
	if (showMemory)
	{
		for (auto mem : memory)
			cout << mem << " | ";
		cout << endl;
	}
	return 0;
}