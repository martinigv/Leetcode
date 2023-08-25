class VideoSharingPlatform {
public:
   
    struct videoData {
        string vstring{};
        int likes{ 0 };
        int dislikes{ 0 };
        int views{ 0 };
    } vd;
    unordered_map<int, videoData> mp;
    set<int> removeSet;
    int count = 0;
    int upload(const string& video) {
        vd.vstring = video;
        if(!removeSet.empty()) {
            int index = *removeSet.begin();
            mp.emplace(index, vd);
            removeSet.erase(removeSet.begin());
            return index;
        }
        mp.emplace(count, vd);
        return count++;
    }

    void remove(int videoId) {
        auto it = mp.find(videoId);
        if (it != mp.end()) {
            mp.erase(videoId);
            removeSet.insert(videoId);
        }
    }

    string watch(int videoId, int startMinute, int endMinute) {
        auto it = mp.find(videoId);
        if (it != mp.end()) {
            mp[videoId].views++;
            int length = mp[videoId].vstring.length();
            return mp[videoId].vstring.substr(startMinute, min(endMinute, length-1)+1);
        }
        return "-1";
    }

    void like(int videoId) {
        auto it = mp.find(videoId);
        if (it != mp.end()) {
            mp[videoId].likes++;
        }
    }

    void dislike(int videoId) {
        auto it = mp.find(videoId);
        if (it != mp.end()) {
            mp[videoId].dislikes++;
        }
    }

    vector<int> getLikesAndDislikes(int videoId) {
        auto it = mp.find(videoId);
        if (it != mp.end()) {
            return {mp[videoId].likes, mp[videoId].dislikes};
        }
        return {-1};
    }

    int getViews(int videoId) {
        auto it = mp.find(videoId);
        if (it != mp.end()) {
            return mp[videoId].views;
        }
        return -1;
    }
    
};