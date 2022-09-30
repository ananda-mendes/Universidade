def abduction(kb, obs):

    if not obs:
        return []

    explanation = []
    logicalConsequence = botton_up(kb)
    observationRules = []

    for o in obs:
        observationRules += kb["rules"][o]

    for rule in observationRules:
        isExplanation = True
        ruleAssumables = []
        for ass in rule:
            ruleAssumables.append(ass)

            if not (ass in logicalConsequence or ass in kb["assumables"]):
                isExplanation = False
                ruleAssumables = []
                break

        if isExplanation and not (rule in explanation):
            explanation += [rule]

    return explanation


def botton_up(kb):
    C = []

    if 'assumables' in kb:
        for a in kb['assumables']:
            if ask(a):
                C.append(a)

    new_consequence = True

    while new_consequence:
        new_consequence = False 

        for head in kb['rules']:
            if head not in C: # Very innefient
                for body in kb['rules'][head]:
                    if not set(body).difference(set(C)): # Very innefient
                        C.append(head)
                        new_consequence = True

    return C



def ask(askable):
    ans = input(f'Is {askable} true?')
    return True if ans.lower() in ['sim','s','yes','y'] else False


if __name__ == "__main__":
    
    kb = {'rules':{'a':[['b','c']],
                   'b':[['d'],['c']],
                   'd':[['h']],
                   'g':[['a','b','c']],
                   'f':[['h','b']]},
            'assumables':['c','e']}

    obs = ['a', 'b', 'd']

    print(f"The explanation of {obs}: is {abduction(kb, obs)}")