import numpy as np
import copy
import random

def different_column_violations(sol):
    conflicts = 0

    for i in range(len(sol)):
        for j in range(len(sol)):
            if i != j and sol[i] == sol[j]:
                conflicts += 1

    return conflicts


def different_diagonal_violations(sol):
    conflicts = 0
    for i in range(len(sol)):
        for j in range(len(sol)):
            deltax = abs(sol[i] - sol[j])
            deltay = abs(i - j)
            if (deltax == deltay).all():
                conflicts += 1

    return conflicts


def obj(sol):
    return different_diagonal_violations(sol) + different_column_violations(sol)


def pop_int(n, k):
    return [np.random.permutation(n) for i in range(k)]


def mutation(sol):
    neighbor = copy.copy(sol)

    idx1 = np.random.randint(0, len(sol))
    idx2 = np.random.randint(0, len(sol))

    neighbor[idx1], neighbor[idx2] = neighbor[idx2], neighbor[idx1]

    return neighbor


def crossover(sol1, sol2):
    mask = np.random.randint(2, size=len(sol1))
    f1 = copy.copy(sol1)
    for i in range(len(sol1)):
        if mask[i] == 0:
            f1[i] = sol2[i]

    f2 = copy.copy(sol2)
    for i in range(len(sol2)):
        if mask[i] == 0:
            f2[i] = sol1[i]

    return f1, f2


def select(sol):
    best = 0
    best_score = obj(sol[0])
    for pos in range(len(sol)):
        score = obj(sol[pos]) 
        if score < best_score:
            best = pos
            best_score = score

    return best

if __name__ == '__main__':
    pop = pop_int(10, 8)

    probability_mutation = 0.2
    probability_crossover = 0.7
    maxit = 1000
    tournamentLen = 50

    pos_p1, pos_p2, best_pos, best_score = 0
    f, f1, f2 = []

    for i in range(maxit):
        for j in range(tournamentLen):
            prob = random.random()
            if prob < probability_crossover:
                pos_p1 = random.randint(0, len(pop)-1)
                pos_p2 = random.randint(0, len(pop)-1)
                if pos_p1 == pos_p2:
                    pos_p2 = random.randint(0, len(pop)-1)

                f1, f2 = crossover(pop[pos_p1], pop[pos_p2])
                f.append(f1)
                f.append(f2)
                prob = random.random()
                if prob < probability_mutation:
                    mutation(f)

                score_p1 = obj(pop[pos_p1])
                score_f = obj(f[select(f)])

                if score_f < score_p1:
                    pop[pos_p1] = f[select(f)]

                f.clear()

        best_pos = select(pop)
        best_score = obj(pop[best_pos])

    print(f"Position: {best_pos} \nScore: {best_score} \nPop: {pop[best_pos]}")
