import sys
import math


def main():
    w, l, d = (float(x) for x in sys.stdin.readline().split())
    bronze, silver, gold, platnium, diamond = 0, 0, 0, 0, 0
    for win in range(21):
        for loss in range(21):
            draw = 20 - win - loss
            if draw < 0:
                continue
            summand = math.factorial(20) // math.factorial(win) // math.factorial(loss) // math.factorial(draw) \
                * w ** win * l ** loss * d ** draw
            if win - loss < -10:
                bronze += summand
            elif win - loss < 0:
                silver += summand
            elif win - loss < 10:
                gold += summand
            elif win - loss < 20:
                platnium += summand
            else:
                diamond += summand
    sys.stdout.write("{0:.8f}\n".format(bronze))
    sys.stdout.write("{0:.8f}\n".format(silver))
    sys.stdout.write("{0:.8f}\n".format(gold))
    sys.stdout.write("{0:.8f}\n".format(platnium))
    sys.stdout.write("{0:.8f}\n".format(diamond))


main()
