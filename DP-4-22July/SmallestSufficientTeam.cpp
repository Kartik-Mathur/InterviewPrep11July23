#define ll long long
class Solution {
public:
	ll solve(vector<string>& req_skills,
	         vector<vector<string>>& people,
	         unordered_map<ll, ll> &peopleMask,
	         map<pair<ll, ll>, ll> &dp,
	         ll currentMask = 0, ll i = 0) {
		// base case
		if (i == people.size()) {
			if (currentMask == ((1 << req_skills.size()) - 1)) return dp[ {currentMask, i}] = 0;
			return dp[ {currentMask, i}] = (1ll << 62) - 1;
		}

		if (dp.find({currentMask, i}) != dp.end()) return dp[ {currentMask, i}];

		// recursive case
		ll op1, op2;
		op1 = op2 = (1ll << 62) - 1;
		if (peopleMask[i]) {
			op1 = solve(req_skills, people, peopleMask, dp,
			            currentMask | peopleMask[i], i + 1);
			op1 |= (1ll << i);
		}
		op2 = solve(req_skills, people, peopleMask, dp, currentMask, i + 1);

		ll pplCntop1 = __builtin_popcountll(op1);
		ll pplCntop2 = __builtin_popcountll(op2);
		if (pplCntop1 < pplCntop2) return dp[ {currentMask, i}] = op1;
		return dp[ {currentMask, i}] = op2;
	}

	vector<int> smallestSufficientTeam(vector<string>& req_skills,
	                                   vector<vector<string>>& people) {
		unordered_map<string, ll> skillId;
		map<pair<ll, ll>, ll> dp;

		for (ll i = 0; i < req_skills.size(); ++i)
		{
			skillId[req_skills[i]] = i;
		}

		unordered_map<ll, ll> peopleMask;

		for (ll i = 0 ; i < people.size() ; i++) {
			ll mask = 0;
			for (auto skill : people[i]) {
				ll id = skillId[skill];
				mask |= (1 << id);
			}

			peopleMask[i] = mask;
		}

		ll ans = solve(req_skills, people, peopleMask, dp);
		ll i = 0;
		vector<int> x;
		while (ans) {
			if (1 & ans) {
				x.push_back(i);
			}
			i++;
			ans >>= 1;
		}

		return x;
	}
};









