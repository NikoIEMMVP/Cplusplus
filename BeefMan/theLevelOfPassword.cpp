#include <iostream>
#include <string>

int password_size(int size){
    int score_size = 0;
    if(size <= 4){
        score_size += 5;
    }else if(size >= 5 && size <= 7){
        score_size += 10;
    }else if(size >= 8){
        score_size += 25;
    }
    
    return score_size;
}

int password_letter(const std::string& password){
    int count_letter = 0;
    int small_letter = 0;
    int big_letter = 0;
    int score_letter = 0;
    auto sit = password.begin();
    while(sit != password.end()){
        if ((*sit >= 'A') && (*sit <= 'Z')) 
		{
			big_letter++;
		}
		if ((*sit >= 'a') && (*sit <= 'z'))
		{
			small_letter++;
		}
		sit++;
    }
    
    count_letter = small_letter + big_letter;
    if(count_letter == 0){
        score_letter += 0;
    }
	if (((big_letter != 0) && (small_letter == 0)) || ((big_letter == 0) && (small_letter != 0))){
		score_letter += 10;
	}
    if ((big_letter != 0) && (small_letter != 0)){
		score_letter += 20;
	}
    
    return score_letter;
    
}

int password_num(const std::string& password){
    int score_num = 0;
    int num_num = 0;
    auto sit = password.begin();
    while(sit != password.end()){
        if ((*sit > '1') && (*sit < '9')){
		    num_num++;
	    }

        sit++;

    }
    

    if(num_num == 0){
        score_num += 0;
    }
    else if (num_num == 1){
		score_num += 10;
	}
	else if (num_num > 1){
		score_num += 20;
	}

    return score_num;
}

int password_char(const std::string& password){
    int score_char = 0;
    int num_char = 0;
    auto sit = password.begin();
    while(sit != password.end()){
        if (((*sit >= '!') && (*sit <= '/')) || ((*sit >= ':') && (*sit <= '@')) || ((*sit >= '[') && (*sit <= '`')) || ((*sit >= '{') && (*sit <= '~'))){
			num_char++;
		}
        sit++;
    }

    if(num_char == 0){
        score_char += 0;
    }
    else if (num_char == 1){
		score_char += 10;
	}
	else if (num_char > 1){
		score_char += 25;
	}

    return score_char;
    
}

void Safety_level(const std::string& password){
    int score = 0;
    int size = password.size();
    score += password_size(size);
    score += password_letter(password);
    score += password_num(password);
    
    
}


int main()
{
    std::string password;
    while(std::cin >> password){
        Safety_level(password);
    }
    return 0;
}

