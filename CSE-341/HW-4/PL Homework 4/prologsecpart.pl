% Decision tree rules
classify(_, _, _, Feature3, 'Iris-setosa') :-
    Feature3 =< 0.80.
classify(_, _, Feature2, Feature3, 'Iris-versicolor') :-
    Feature3 > 0.80,
    Feature2 =< 4.75,
    Feature3 =< 1.65.
classify(_, _, Feature2, Feature3, 'Iris-virginica') :-
    Feature3 > 0.80,
    Feature2 =< 4.75,
    Feature3 > 1.65.
classify(_, _, Feature2, Feature3, 'Iris-versicolor') :-
    Feature3 > 0.80,
    Feature2 > 4.75,
    Feature3 =< 1.75,
    Feature2 =< 4.95.
classify(_, _, Feature2, Feature3, 'Iris-virginica') :-
    Feature3 > 0.80,
    Feature2 > 4.75,
    Feature3 =< 1.75,
    Feature2 > 4.95,
    Feature3 =< 1.55.
classify(_, _, Feature2, Feature3, 'Iris-versicolor') :-
    Feature3 > 0.80,
    Feature2 > 4.75,
    Feature3 =< 1.75,
    Feature2 > 4.95,
    Feature3 > 1.55,
    Feature2 =< 5.45.
classify(_, _, Feature2, Feature3, 'Iris-virginica') :-
    Feature3 > 0.80,
    Feature2 > 4.75,
    Feature3 =< 1.75,
    Feature2 > 4.95,
    Feature3 > 1.55,
    Feature2 > 5.45.
classify(Feature0, _, Feature2, Feature3, 'Iris-versicolor') :-
    Feature3 > 0.80,
    Feature2 > 4.75,
    Feature3 > 1.75,
    Feature2 =< 4.85,
    Feature0 =< 5.95.
classify(Feature0, _, Feature2, Feature3, 'Iris-virginica') :-
    Feature3 > 0.80,
    Feature2 > 4.75,
    Feature3 > 1.75,
    Feature2 =< 4.85,
    Feature0 > 5.95.
classify(_, _, Feature2, Feature3, 'Iris-virginica') :-
    Feature3 > 0.80,
    Feature2 > 4.75,
    Feature3 > 1.75,
    Feature2 > 4.85.

classify_instance(Feature0, Feature1, Feature2, Feature3, Class) :-
    classify(Feature0, Feature1, Feature2, Feature3, Class).

:- classify_instance(4.9, 2.4, 3.3, 1.0, Class), write(Class), nl.
