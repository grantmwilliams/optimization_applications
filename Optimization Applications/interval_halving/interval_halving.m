function optimum_point = interval_halving(fitness_function,boundary_conditions,start_point)
% This function returns the maximum point of the fitness function within
% the boundary conditions by use of the interval halving technique (similar
% to binary search tree).
fitness = [0, 0];

left_check = start_point - abs(boundary_conditions(1) - start_point)/2;

right_check = start_point + abs(boundary_conditions(2)-start_point)/2;

fitness(1) = get_fitness(fitness_function,boundary_conditions,left_check);
fitness(2) = get_fitness(fitness_function,boundary_conditions,right_check);

[opt,point] = max(fitness);
optimum_point = [point, opt];

end

function fitness = get_fitness(fitness_function,boundary_conditions,input_args )
% Evaluates the fitness function and returns the fitness. Considered
% boundary conditions
if(fitness_function == 1)
    
    if (input_args < boundary_conditions(1) || input_args > boundary_conditions(2)) % if out of bounds
        fitness = -1 * Inf; % arbitrarily small number to make a bad fitness
    else
        fitness = input_args ^ 3;
    end % ends if
    
elseif (fitness_function == 2)
    
    if (input_args < boundary_conditions(1) || input_args > boundary_conditions(2)) % if out of bounds
        fitness = -1 * Inf; % arbitrarily small number to make a bad fitness
    
    else
        fitness = sin(input_args);
    end % ends if
    
elseif (fitness_function == 3)
    
    if (input_args < boundary_conditions(1) || input_args > boundary_conditions(2)) % if out of bounds
        fitness = -1 * Inf; % arbitrarily small number to make a bad fitness
    else
        fitness = tan(input_args)^2 / e^(input_args);
    end % ends if
    
end % ends if 

end % ends function
