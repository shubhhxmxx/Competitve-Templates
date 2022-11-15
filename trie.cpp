struct Node{
	int cp=0;
	int cew=0;
	Node *links[26];

	void put(char ch,Node *node){
		links[ch-'a']=node;
	}
	bool contains(char ch){
		return links[ch-'a']!=NULL;
	}
	Node *get(char ch){
		return links[ch-'a'];
	}
	void increaseend(){
		 cew++;
	}
	void increaseprefix(){
		cp++;
	}
	void deleteprefix(){
		if(cp>0) cp--;
	}
	void deleteend(){
		if(cew) cew--;
	}
	int getend(){
		return cew;
	}
	int getprefix(){
		return cp;
	}

};

