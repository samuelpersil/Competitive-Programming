ll l, r, res = -1;

while(l <= r){
	ll mid = (l + r)/2;
	if(ok(mid)){
		res = mid;
		r = mid - 1;
	}
	else{
		l = mid + 1;
	}
}

cout << res << endl;

//first true

while(l <= r){
    int mid = (l + r) / 2;
    if(check(mid)){
        r = mid - 1;
    }else{
        l = mid + 1;
    }
}

cout << l;

// last true

while(l <= r){
    int mid = (l + r) / 2;
    if(check(mid)){
        l = mid + 1;
    }else{
        r = mid - 1;
    }
}

cout << r;
