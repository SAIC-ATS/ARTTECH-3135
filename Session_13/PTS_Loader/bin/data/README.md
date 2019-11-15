Download this file

https://www.navvis.com/m6-pointclouds

[SAMPLE DATA - PTS](https://cdn2.hubspot.net/hubfs/3339696/Download/NavVisHQ-5thFloor_pts.7z)


```
awk '!(NR%10000)' NavVisHQ-5thFloor.pts > small.pts
```
```
awk '!(NR%1000)' NavVisHQ-5thFloor.pts > medium.pts
```
