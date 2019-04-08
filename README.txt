DEPTH LIMIT DETAILS:
    The depth limit for minimax is implemented by passing the current piece-count and the total allowed piece-count
        as described by the depth-limit parameter to the aiSmartPlay and the minValue/maxValue functions.
        The recursive minValue/maxValue functions test for this goal condition and will evaluate utility 
        of the board at that state using the heuristc of score difference and return it. 

MINIMIX DETAILS:
    Minimax algorithm implemented with a very simple evaluation function, 
        one player's score minus the other player's score, i.e. player1Score - player2Score.
        In this example player 1 is trying to maximize this value while player 2 seeks
        to minimize that value.  
    The function aiPlaySmart acts as the maximizatin player, making call to the recursive
        function minValue, which recursively calls maxValue.

ALPHA-BETA DETAILS:
    Alpha-beta pruning was implemented by adding two parameters to minValue and maxValue functions.
        Parameter alpha describes the minimization player's choice by finding the lowest of the maximum values
        returned by the max player the the min player's child nodes.  Parameter beta describes the maximization
        player's choice by finding the highest of the minimum calues returned by the min player in the max player's
        child nodes. The recursive minValue and maxValue functions return the appropriate value if they find a child
        score less that or greater to the value they are already holding as their best option, effectively pruning the tree.

NODE PRIORITIZATION FOR EXPANSION:
    Node prioritization is implemented using a second heuristic.  In general, it is more strategic to play pieces
        closer to the vertical center-axis of the board because pieces are more available to connect in lines of 4
        in every direction.  Because of this, there is an orderMoves function that prioritizes child nodes
        for expansion based upon this hypothesis.
    Below is tabularized data describing the difference in boards examined using just the minimax, and then with
        a/b pruning added, at three states of the game.  
    Under the given heuristics for node prioritization and utility evaluation, which are quite basic, it can be 
        seen that a/b pruning does not have much effect at the beginning of the game.  This is because the chosen 
        evaluation function is based purely on score, so terminal nodes that have meaningful data are a little bit 
        too far down in the tree.
    Early-to-mid-game comparisons are much more interesting.  This pruning scheme is dramatically more effective
        when the depth limit is odd which makes sense because the AI is the max player so it gets more data 
        about the min player's moves when the depth limit is odd.  A depth limit of 6, 8, or 10 had an 
        almost identical number of boards searched for both minimax and minimax with a/b pruning, however
        the number of boards searched for minimax with a/b pruning with depth limit 7, 9, or 11 is less than half
        of the number searched by plain minimax.
    Late-to-end-game stats were consistent with the observations made in previous states of the game, noting that
        the tree has become a lot smaller so the differences are not as dramatic, however the even/odd depth limit
        trends remain.

NODE PRIORITIZATION BASED ON ITERATIVE DEEPENING:
    I attempted to change the expansion prioritization ordering based upon the evaluation function after a certain
        number of pieces had been played in the hopes of making the a/b pruning more effective.  While this approach
        does demonstrate an improvement over plain minimax, without a better heuristic for scoring the game board 
        this approach does worse than the "closest to center" prioritization described above. 
     

BOARDS EXAMINED (from empty board):
    D = 5:
        plain mini-max = a/b pruing = 19, 607
    D = 6:
        plain mini-max = a/b pruing = 137,256
    D = 7:
        plain mini-max = a/b pruing = 960,792
    D = 8:
        plain mini-max:    6,725,250
        a/b pruing:        6,665,736
    D = 9:
        plain mini-max:   47,069,400
        a/b pruing:       46,809,580
    D = 10:
        plain mini-max:  329,351,442
        a/b pruing:      321,328,576

BOARDS EXAMINED (with 13 pieces already placed):
    D = 5:
        plain mini-max:       9,327
        a/b pruing:           3,929
    D = 6:
        plain mini-max:      55,889
        a/b pruing:          55,889
    D = 7:
        plain mini-max:     334,104
        a/b pruing:         141,866
    D = 8:
        plain mini-max:   1,989,674
        a/b pruing:       1,989,674
    D = 9:
        plain mini-max:  11,783,444 
        a/b pruing:       5,070,712
    D = 10:
        plain mini-max:  69,256,820
        a/b pruing:      69,256,346
    D = 11:
        plain mini-max: 403,299,212 
        a/b pruning:    177,206,098

BOARDS EXAMINED (with 28 pieces placed):
    D = 5:
        plain mini-max:       1,227
        a/b pruing:             798
    D = 6:
        plain mini-max:       4,473
        a/b pruing:           4,473
    D = 7:
        plain mini-max:      15,701
        a/b pruing:          11,317
    D = 8:
        plain mini-max:      52,843
        a/b pruing:          52,182
    D = 9:
        plain mini-max:     169,435
        a/b pruing:         132,537
    D = 10:
        plain mini-max:     512,407
        a/b pruing:         469,501
    D = 11:
        plain mini-max:   1,439,641
        a/b pruing:       1,208,965

