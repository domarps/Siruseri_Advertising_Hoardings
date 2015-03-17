# Siruseri_Advertising_Hoardings

Downtown Siruseri is booming and the main road is now lined with a continuous row of skyscrapers. For aesthetic reasons, the Siruseri Municipal Corporation had banned advertising hoardings along the main road.

The High Court has squashed the Municipal Corporation's ban as unconstitutional and ruled that rectangular hoardings may be put up parallel to the main road, along the walls of the skyscrapers lining the road. The only restriction is that a hoarding may not extend above the height of any building along its length.

Advertising agencies across the city are buzzing witth excitement at the news and accounts executives are busy calculating how large they can make their hoardings, in terms of total area, to collect maximum revenue from advertisers.

For instance suppose the Siruseri skyline appears as follows, where the number at the top of each building specifies its height while the number at the bottom of each building specifies its width, both quantities measured in metres.

*Input format*

The first line of input is an integer N, the number of skyscrapers. This is followed by N lines of input describing the skyscrapers in left to right order. Each of these lines consists of two integers W and H, specifying the width and height of the skyscraper, respectively.

*Output format*

A single integer denoting the maximum area of a legal hoarding given the arrangement of skyscrapers.
Test Data

In 10% of the inputs, N = 105. In the remaining 90% of the inputs, you may assume 1 ≤ N ≤ 5000. In 10% of the inputs, 1 ≤ N ≤ 500.

*Sample input*

8
20 30
10 50
30 70
20 50
10 10
20 55
30 80
20 40

*Sample output*
3000

In this situation, the biggest legal hoarding spans the second, third and fourth buildings with an area of 60 × 50 = 3000 square metres. The next best possibility is a hoarding of 70 × 40 = 2800 square metres, spanning the last three buildings.

Your task is to compute the maximum area that a hoarding can have for a given arrangement of skyscrapers.
