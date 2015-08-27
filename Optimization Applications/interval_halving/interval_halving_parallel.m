function optimum_point = interval_halving_parallel(fitness_function,boundary_conditions,start_point)
% This function returns the maximum point of the fitness function within
% the boundary conditions by use of the interval halving technique (similar
% to binary search tree).
fitness = [0, 0];
left_stop = 1;
right_stop = 1;

left_check = start_point - abs(boundary_conditions(1) - start_point)/2;

right_check = start_point + abs(boundary_conditions(2)-start_point)/2;

fitness(1) = get_fitness(fitness_function,boundary_conditions,left_check);
fitness(2) = get_fitness(fitness_function,boundary_conditions,right_check);
lfit = -1 * Inf;
rfit = -1 * Inf;
while (left_stop == 1 || right_stop == 1)
    
    if (left_stop == 1)
        
        left_distance = left_check - (abs(boundary_conditions(1) - left_check))/2; % How far are we going to move the point on the left side
        
        lfitl = get_fitness(fitness_function,boundary_conditions,(left_check-left_distance)); % Fitness after we move the point left_distance to the left
        lfitr = get_fitness(fitness_function,boundary_conditions,(left_check+left_distance)); % Fitness after we move the point left_distance to the right
        
        if (lfit == fitness(1))
            left_stop = 0; % our value hasnt changed so stop left side. we found an optimum there.
        else
            lfits = [fitness(1),lfitl,lfitr];
            [lfit,lidx] = max(lfits); % Find the best fitness on left side and the point where it occurs      
            fitness(1) = lfit; % Assign new best fitness
            
            if (lidx == 2)
                left_check = left_check - left_distance; % If point was left of current point assign current point to the left test point
            elseif (lidx == 3)
                left_check = left_check + left_distance; % If point was right of current point assign current point to the right test point
            end % end if
        
        end % end if
        
    end % end if
        
    if (right_stop == 1)
        
        right_distance = right_check - (abs(boundary_conditions(2) - right_check))/2;
        
        rfitl = get_fitness(fitness_function,boundary_conditions,(right_check-right_distance));
        rfitr = get_fitness(fitness_function,boundary_conditions,(right_check+right_distance));
        
        if (rfit == fitness(2))
           right_stop = 0; % our value hasnt changed so stop left side. we found an optimum
        else
        
            rfits = [fitness(2),rfitl,rfitr];
            [rfit,ridx] = max(rfits); % Find the best fitness on left side and the point where it occurs      
            fitness(2) = rfit; % Assign new best fitness
            
            if (ridx == 2)
                right_check = right_check - right_distance; % move left
            elseif (ridx == 3)
                right_check = right_check + right_distance; % move right
            end % end if
        
        end % end if
        
    end % end if
    
end % End while
check = [left_check,right_check];

[opt_y,opt_x] = max(fitness);
optimum_point = [check(opt_x),opt_y];

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
        fitness = tan(input_args)^2 / exp(input_args);
    end % ends if
    
end % ends if 

end % ends function
