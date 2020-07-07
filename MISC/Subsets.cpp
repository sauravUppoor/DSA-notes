// Finding all subsets of an array


for(int b = 0; b < (1<<n); ++b) {
	vi sb;
	
	F0R(i,n) {
		if(b&(1<<i)) sb.pb(a[i]);
	}
	//vector sb will contain all the elements in the current subset
}

