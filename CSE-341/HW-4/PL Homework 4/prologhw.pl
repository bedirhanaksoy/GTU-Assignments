% Facts
% Delivery personnel
delivery_personnel(delivery_personel_1, 10, 12, none, institute_x).
delivery_personnel(delivery_personel_2, 15, 20, object_id_3, library).
delivery_personnel(delivery_personel_3, 20, 8, none, lecture_hall_a).

% Places
place(admin_office).
place(cafeteria).
place(engineering_building).
place(library).
place(social_sci_building).
place(lecture_hall_a).
place(institute_y).
place(institute_x).

% Objects
object(object_id_1, 5, admin_office, library, low, none).
object(object_id_2, 8, social_sci_building, lecture_hall_a, medium, none).
object(object_id_3, 12, institute_x, cafeteria, high, delivery_personel_2). % In transit with delivery person 2
object(object_id_4, 6, lecture_hall_a, admin_office, medium, none).
object(object_id_5, 10, engineering_building, institute_x, high, none).

% Map with travel times
route(admin_office, admin_office, 0).
route(admin_office, cafeteria, 4).
route(admin_office, engineering_building, 3).
route(admin_office, library, 1).
route(admin_office, social_sci_building, 6).
route(admin_office, institute_x, 14).
route(admin_office, lecture_hall_a, 5).
route(admin_office, institute_y, 4).

route(engineering_building, engineering_building, 0).
route(engineering_building, library, 5).
route(engineering_building, lecture_hall_a, 2).
route(engineering_building, admin_office, 3).
route(engineering_building, institute_y, 5).
route(engineering_building, cafeteria, 7).
route(engineering_building, social_sci_building, 6).
route(engineering_building, institute_x, 14).

route(lecture_hall_a, lecture_hall_a, 0).
route(lecture_hall_a, institute_y, 3).
route(lecture_hall_a, engineering_building, 2).
route(lecture_hall_a, library, 6).
route(lecture_hall_a, admin_office, 5).
route(lecture_hall_a, cafeteria, 9).
route(lecture_hall_a, social_sci_building, 8).
route(lecture_hall_a, institute_x, 16).

route(library, library, 0).
route(library, institute_y, 3).
route(library, cafeteria, 5).
route(library, social_sci_building, 2).
route(library, admin_office, 1).
route(library, engineering_building, 5).
route(library, institute_x, 10).
route(library, lecture_hall_a, 6).

route(cafeteria, cafeteria, 0).
route(cafeteria, social_sci_building, 2).
route(cafeteria, admin_office, 4).
route(cafeteria, library, 5).
route(cafeteria, institute_x, 10).
route(cafeteria, engineering_building, 7).
route(cafeteria, lecture_hall_a, 9).
route(cafeteria, institute_y, 7).

route(social_sci_building, social_sci_building, 0).
route(social_sci_building, institute_x, 8).
route(social_sci_building, library, 2).
route(social_sci_building, cafeteria, 2).
route(social_sci_building, admin_office, 3).
route(social_sci_building, institute_y, 5).
route(social_sci_building, engineering_building, 7).
route(social_sci_building, lecture_hall_a, 8).

route(institute_x, institute_x, 0).
route(institute_x, social_sci_building, 8).
route(institute_x, cafeteria, 10).
route(institute_x, library, 10).
route(institute_x, institute_y, 13).
route(institute_x, admin_office, 11).
route(institute_x, engineering_building, 14).
route(institute_x, lecture_hall_a, 16).

route(institute_y, institute_y, 0).
route(institute_y, lecture_hall_a, 3).
route(institute_y, library, 3).
route(institute_y, engineering_building, 5).
route(institute_y, admin_office, 4).
route(institute_y, cafeteria, 7).
route(institute_y, social_sci_building, 5).
route(institute_y, institute_x, 13).


% Rules

% Check if a delivery person is available to pick and deliver an object
available_delivery_person(ObjectID, AvailablePersons) :-
    object(ObjectID, Weight, PickupPlace, DropPlace,_, Status),
    (Status = none ->  % Check if the object is not in transit
        route_delivery_persons(ObjectID, Weight, PickupPlace, DropPlace, AvailablePersons)
    ;  % If the object is in transit, print the delivery person information
        format('~w is in transit with ~w.~n', [ObjectID, Status]),
        AvailablePersons = []
    ).

% Helper rule to find available delivery persons
route_delivery_persons(ObjectID, Weight, PickupPlace, DropPlace, AvailablePersons) :-
    findall(
        PersonID,
        (
            delivery_personnel(PersonID, Capacity, WorkHour, none, CurrentLocation),
            Capacity >= Weight,
            route(CurrentLocation, PickupPlace, TravelTime1),
            route(PickupPlace, DropPlace, TravelTime2),
            TotalTime is TravelTime1 + TravelTime2,
            TotalTime =< WorkHour
        ),
        AvailablePersons
    ),
    print_delivery_persons(ObjectID, AvailablePersons).

% Helper rule to print delivery persons
print_delivery_persons(ObjectID, AvailablePersons) :-
    (
        AvailablePersons = []
        -> write('No available delivery persons.')
        ;  print_persons(ObjectID, AvailablePersons)
    ),
    nl.

% Helper rule to print delivery persons
print_persons(_, []) :- !.
print_persons(ObjectID, [PersonID | Rest]) :-
    delivery_personnel(PersonID, _, _, none, _),
    format('~w can deliver ~w.~n', [PersonID, ObjectID]),
    print_persons(ObjectID, Rest).

% Example: Check for available delivery person for object_4
?- available_delivery_person(object_id_3, _).
% This will print available delivery persons along with their IDs.

