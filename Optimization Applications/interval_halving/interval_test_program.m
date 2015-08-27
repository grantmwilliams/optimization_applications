%% Interval Halving Test Program
% This program is designed to test the interval halving technique with a
% number of different functions and boundary conditions.
%
% Program by Grant Williams - Version 1.0.0

fitness_function = 1;
% 1 for f(x) = x^3
% 2 for f(x) = sin(x)
% 3 for f(x) = tan^2(x)/e^x

if (fitness_function == 1)
    boundary_conditions = [-10, 10];
    
elseif (fitness_function == 2)
    boundary_conditions = [- 2 * pi, 2 * pi];
    
elseif (fitness_function == 3)
    boundary_conditions = [-3, 3];
end % end fitness function boundary conditions