from abc import ABC, abstractmethod
from ex0.creature import Creature
from ex1.capability import TransformCapability, HealCapability
from .error import BattleError


class BattleStrategy(ABC):
    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        pass

    @abstractmethod
    def act(self, creature: Creature) -> str:
        pass


class NormalStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return True

    def act(self, creature: Creature) -> str:
        return creature.attack()


class AggressiveStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, TransformCapability)

    def act(self, creature: Creature) -> str:
        if not isinstance(creature, TransformCapability):
            raise BattleError(
                f"Invalid Creature '{creature.name}' "
                "for this aggressive strategy"
            )
        transform_m = creature.transform()
        attack_m = creature.attack()
        revert_m = creature.revert()
        return f"{transform_m}\n{attack_m}\n{revert_m}"


class DefensiveStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, HealCapability)

    def act(self, creature: Creature) -> str:
        if not isinstance(creature, HealCapability):
            raise BattleError(
                f"Invalid Creature '{creature.name}' "
                "for this defensive strategy"
            )
        attack_m = creature.attack()
        heal_m = creature.heal()
        return f"{attack_m}\n{heal_m}"
