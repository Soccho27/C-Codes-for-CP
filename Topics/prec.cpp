
const int sz=5000;
int fact[sz];

void prec(){
    fact[0] = 1;
    for(int i = 1; i < sz;i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

vector<int> primes, isPrime(sz + 1, 1);

void prec(){
	isPrime[0] = 0, isPrime[1] = 0;
	for(int i = 2;i <= sz; i++){
        if(isPrime[i])primes.push_back(i);
        if(sz / i < i)continue;
		for(int j = i * i; j <= sz; j+= i){
			isPrime[j] = 0;
		}
	}
}

vector<int> divi[sz + 5];

void prec(){
    for(int i = 1; i <= sz; i++){
        for(int j = i; j <= sz; j+=i){
            divi[j].push_back(i);
        }
    }
}


vector<int> primes, spfa(sz + 1);

void prec(){
	for(int i = 0; i <= sz; i++)spfa[i] = i;
	for(int i = 2;i <= sz; i++){
        if(spfa[i] != i)continue;
        primes.push_back(i);
        if(sz / i < i)continue;
		for(int j = i * i; j <= sz; j+= i){
			if(spfa[j] != j)continue;
            spfa[j] = i;
		}
	}
}