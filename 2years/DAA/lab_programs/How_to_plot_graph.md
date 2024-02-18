# Plot with xgraph

## Install xgraph
```bash
wget https://www.xgraph.org/linux/xgraph_4.38_linux64.tar.gz

tar xvfz xgraph_4.38_linux64.tar.gz

echo "alias xgraph=/home/username/XGraph4.38_linux64/bin/xgraph" >> ~/.bashrc

source ~/.bashrc

xgraph
```

## Create a file with data
```bash
gedit data.txt
```
- add data in the following format
```
x1 y1
x2 y2
x3 y3
```
- for example
```
5000 10000
10000 20000
15000 30000
20000 40000
```

## Plot the graph
```bash
xgraph data.txt -x "x-axis" -y "y-axis" -t "title"
```

## Example
```bash
xgraph data.txt -x "Input Size" -y "Time" -t "Time Complexity"
```
